#include "ScalarConverter.hpp"

bool ScalarConverter::isValidBody(const std::string &body) {
	bool seenDigit = false;
	bool seenDot = false;
	size_t len = body.length();

	if (!body.empty() && body.back() == 'f') {
		len--;
	}
	for (std::size_t i = 0; i < len; ++i) {
		char c = body[i];
		if (c == '-' || c == '+') {
			if (i != 0) return false; // sign only allowed at start
		}
		else if (c == '.') {
			if (seenDot) return false; // only one dot allowed
			seenDot = true;
			if (i == 0 || i == len - 1) return false;
		}
		else if (std::isdigit(static_cast<unsigned char>(c))) {
			seenDigit = true;
		}
		else {
			return false; // anything else is invalid
		}
	}
	return seenDigit; // must have at least one actual digit
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

ScalarType ScalarConverter::determineType(const std::string &input)
{
	if (input.length() == 1 && !std::isdigit(static_cast<unsigned char>(input[0])))
	{
		return ScalarType::CHAR;
	}
	if (input == "nanf" || input == "+inff" || input == "-inff")
		return ScalarType::FLOAT;
	if (input == "nan" || input == "+inf" || input == "-inf")
		return ScalarType::DOUBLE;
	if (isValidBody(input))
	{
		if (input.back() == 'f')
			return ScalarType::FLOAT;
		else if (intPossibleFrom(std::stod(input)) && !input.contains("."))
			return ScalarType::INT;
		else
			return ScalarType::DOUBLE;
	}
	return ScalarType::INVALID;
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

static void printFloat(float f) {
	std::cout << "float: ";
	if (std::isnan(f)) {
		std::cout << "nanf" << std::endl;
	} else if (std::isinf(f)) {
		std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
	} else {
		std::cout << f;
		if (f == static_cast<float>(static_cast<long long>(f)))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
}

static void printDouble(double d) {
	std::cout << "double: ";
	if (std::isnan(d)) {
		std::cout << "nan" << std::endl;
	} else if (std::isinf(d)) {
		std::cout << (d > 0 ? "+inf" : "-inf") << std::endl;
	} else {
		std::cout << d;
		if (d == static_cast<double>(static_cast<long long>(d)))
			std::cout << ".0";
		std::cout << std::endl;
	}
}

void ScalarConverter::convert(const std::string &input) {
	if (input.empty()) {
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
		return;
	}

	ScalarType type = determineType(input);

	if (type == ScalarType::INVALID) {
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
		return;
	}

	double asDouble = 0.0;
	char literalChar = 0;
	bool sourceIsChar = false;

	switch (type) {
		case ScalarType::CHAR:
			literalChar = input[0];
			sourceIsChar = true;
			asDouble = static_cast<double>(literalChar);
			break;
		case ScalarType::INT:
			asDouble = static_cast<double>(std::stoi(input));
			break;
		case ScalarType::FLOAT:
			asDouble = static_cast<double>(std::stof(input));
			break;
		case ScalarType::DOUBLE:
			asDouble = std::stod(input);
			break;
		case ScalarType::INVALID:
			break; // unreachable, handled above
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
	printFloat(static_cast<float>(asDouble));
	printDouble(asDouble);
}
