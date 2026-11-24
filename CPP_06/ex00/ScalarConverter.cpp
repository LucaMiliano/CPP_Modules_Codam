#include "ScalarConverter.hpp"

#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

// ---- literal recognition ----------------------------------------------------
//
// Accepted forms (decimal C++ literal shapes, optional leading sign):
//   char    : a single non-digit character
//   int     : 42   -42
//   double  : 4.2  4.  .5  -4.2
//   float   : 4.2f 4.f .5f -4.2f      (a float needs the dot, like in C++: "1f" is invalid)
//   special : nan nanf inf inff +inf +inff -inf -inff
//
// Anything else (1f, 1.2.3, 1e5, 0x10, "", ...) is rejected.

// Maps the pseudo-literals to their value. Returns false for anything else.
static bool pseudoLiteralValue(const std::string &input, double &value) {
	const double inf = std::numeric_limits<double>::infinity();

	if (input == "nan" || input == "nanf")
		value = std::numeric_limits<double>::quiet_NaN();
	else if (input == "inf" || input == "inff" || input == "+inf" || input == "+inff")
		value = inf;
	else if (input == "-inf" || input == "-inff")
		value = -inf;
	else
		return false;
	return true;
}

bool ScalarConverter::isValidBody(const std::string &body) {
	std::size_t len = body.length();
	std::size_t i = 0;
	std::size_t intDigits = 0;
	std::size_t fracDigits = 0;
	bool hasSuffix = false;
	bool hasDot = false;

	if (len > 0 && body[len - 1] == 'f') {
		hasSuffix = true;
		len--;
	}
	if (i < len && (body[i] == '+' || body[i] == '-'))
		i++;
	while (i < len && std::isdigit(static_cast<unsigned char>(body[i]))) {
		i++;
		intDigits++;
	}
	if (i < len && body[i] == '.') {
		hasDot = true;
		i++;
		while (i < len && std::isdigit(static_cast<unsigned char>(body[i]))) {
			i++;
			fracDigits++;
		}
	}
	if (i != len)
		return false; // leftover characters
	if (intDigits + fracDigits == 0)
		return false; // needs at least one digit ("", "+", ".", ".f")
	if (hasSuffix && !hasDot)
		return false; // "1f" is not a C++ literal, "1.f" is
	return true;
}

// ---- parsing (no exceptions) --------------------------------------------------

// Overflow (ERANGE with an infinite result) means the literal does not fit the type.
// Underflow (ERANGE with 0 or a denormal) is fine: the value is just very small.
static bool parseDouble(const std::string &s, double &out) {
	errno = 0;
	out = std::strtod(s.c_str(), nullptr);
	return !(errno == ERANGE && std::isinf(out));
}

// strtof stops at the trailing 'f', which isValidBody already validated.
static bool parseFloat(const std::string &s, float &out) {
	errno = 0;
	out = std::strtof(s.c_str(), nullptr);
	return !(errno == ERANGE && std::isinf(out));
}

// ---- helpers: decide BEFORE casting whether a target conversion is safe ----

static bool charPossibleFrom(double value) {
	// nan/inf can never become a char; must also fit char's range
	if (std::isnan(value) || std::isinf(value))
		return false;
	if (value < static_cast<double>(std::numeric_limits<char>::min())
		|| value > static_cast<double>(std::numeric_limits<char>::max()))
		return false;
	return true;
}

static bool intPossibleFrom(double value) {
	if (std::isnan(value) || std::isinf(value))
		return false;
	if (value < static_cast<double>(std::numeric_limits<int>::min())
		|| value > static_cast<double>(std::numeric_limits<int>::max()))
		return false;
	return true;
}

static bool floatPossibleFrom(double value) {
	// nan and inf do exist as floats (nanf, +inff), so they stay possible.
	// A finite double outside float's range does not: casting it is UB, and
	// printing +inff would claim the input was infinity.
	if (std::isnan(value) || std::isinf(value))
		return true;
	return std::fabs(value) <= static_cast<double>(std::numeric_limits<float>::max());
}

ScalarType ScalarConverter::determineType(const std::string &input)
{
	double value;

	if (input.length() == 1 && !std::isdigit(static_cast<unsigned char>(input[0])))
		return ScalarType::CHAR;
	if (pseudoLiteralValue(input, value))
		return input[input.length() - 1] == 'f' ? ScalarType::FLOAT : ScalarType::DOUBLE;
	if (!isValidBody(input))
		return ScalarType::INVALID;
	if (input[input.length() - 1] == 'f')
		return ScalarType::FLOAT;
	if (input.find('.') != std::string::npos)
		return ScalarType::DOUBLE;
	// digits only: an int if it fits, otherwise it can only be a double
	if (parseDouble(input, value) && intPossibleFrom(value))
		return ScalarType::INT;
	return ScalarType::DOUBLE;
}

// ---- printing -------------------------------------------------------------------

static void printAllImpossible() {
	std::cout << "char: impossible\n"
			  << "int: impossible\n"
			  << "float: impossible\n"
			  << "double: impossible" << std::endl;
}

static void printChar(bool possible, char c) {
	std::cout << "char: ";
	if (!possible) {
		std::cout << "impossible" << std::endl;
	} else if (!std::isprint(static_cast<unsigned char>(c))) {
		std::cout << "Non displayable" << std::endl;
	} else {
		std::cout << "'" << c << "'" << std::endl;
	}
}

// Prints a finite value, never in scientific notation.
//  - whole numbers: fixed, exactly one decimal ("42.0", "2147483648.0")
//  - others: fixed, with enough decimals to show `significantDigits` significant
//    digits, then trailing zeros are dropped ("1000000.5", "0.1")
template <typename T>
static void printFinite(T value, int significantDigits) {
	std::ostringstream out;

	if (std::floor(value) == value) {
		out << std::fixed << std::setprecision(1) << value;
		std::cout << out.str();
		return;
	}
	int exponent = static_cast<int>(std::floor(std::log10(std::fabs(value))));
	int decimals = significantDigits - 1 - exponent;
	if (decimals < 1)
		decimals = 1;
	out << std::fixed << std::setprecision(decimals) << value;

	std::string text = out.str();
	std::size_t last = text.find_last_not_of('0');
	if (text[last] == '.')
		last++; // keep one digit after the dot
	text.erase(last + 1);
	std::cout << text;
}

// `significantDigits` is how many digits the *source* literal could really carry,
// so a float source does not make the double line show float rounding noise.
static void printFloat(float f, int significantDigits) {
	std::cout << "float: ";
	if (std::isnan(f)) {
		std::cout << "nanf" << std::endl;
	} else if (std::isinf(f)) {
		std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
	} else {
		if (significantDigits > std::numeric_limits<float>::digits10)
			significantDigits = std::numeric_limits<float>::digits10;
		printFinite(f, significantDigits);
		std::cout << "f" << std::endl;
	}
}

static void printDouble(double d, int significantDigits) {
	std::cout << "double: ";
	if (std::isnan(d)) {
		std::cout << "nan" << std::endl;
	} else if (std::isinf(d)) {
		std::cout << (d > 0 ? "+inf" : "-inf") << std::endl;
	} else {
		printFinite(d, significantDigits);
		std::cout << std::endl;
	}
}

// ---- conversion -------------------------------------------------------------------

void ScalarConverter::convert(const std::string &input) {
	ScalarType type = determineType(input);
	double asDouble = 0.0;
	int sourceDigits = std::numeric_limits<double>::digits10;
	char literalChar = 0;
	bool sourceIsChar = false;

	switch (type) {
		case ScalarType::INVALID:
			printAllImpossible();
			return;
		case ScalarType::CHAR:
			literalChar = input[0];
			sourceIsChar = true;
			asDouble = static_cast<double>(literalChar);
			break;
		case ScalarType::INT: {
			// determineType already checked it fits; going through int avoids "-0" becoming -0.0
			double parsed = 0.0;
			if (!parseDouble(input, parsed)) {
				printAllImpossible();
				return;
			}
			asDouble = static_cast<double>(static_cast<int>(parsed));
			break;
		}
		case ScalarType::FLOAT: {
			double special = 0.0;
			float parsed = 0.0f;
			if (pseudoLiteralValue(input, special)) {
				asDouble = special;
			} else if (parseFloat(input, parsed)) {
				asDouble = static_cast<double>(parsed);
			} else {
				printAllImpossible(); // the literal does not fit in a float
				return;
			}
			sourceDigits = std::numeric_limits<float>::digits10;
			break;
		}
		case ScalarType::DOUBLE:
			if (!pseudoLiteralValue(input, asDouble) && !parseDouble(input, asDouble)) {
				printAllImpossible(); // the literal does not fit in a double
				return;
			}
			break;
	}

	if (sourceIsChar) {
		printChar(true, literalChar);
	} else {
		bool ok = charPossibleFrom(asDouble);
		printChar(ok, ok ? static_cast<char>(asDouble) : 0);
	}
	if (intPossibleFrom(asDouble))
		std::cout << "int: " << static_cast<int>(asDouble) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (floatPossibleFrom(asDouble))
		printFloat(static_cast<float>(asDouble), sourceDigits);
	else
		std::cout << "float: impossible" << std::endl;
	printDouble(asDouble, sourceDigits);
}
