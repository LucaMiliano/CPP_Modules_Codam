#include "ScalarConverter.hpp"


bool ScalarConverter::isValidBody(const std::string &body) {
	bool seenDigit = false;
	bool seenDot = false;
	size_t len = body.length();

	if (body.back() == 'f') {
		len--;
	}
	for (std::size_t i = 0; i < len; ++i) {
		char c = body[i];
		if (c == '-' || c == '+') {
			if (i != 0) return false; // sign only allowed at the very start
		}
		else if (c == '.') {
			if (seenDot) return false; // only one dot allowed
			seenDot = true;
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

ScalarType ScalarConverter::determineType(const std::string &input) {
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'' 
	&& std::isprint(static_cast<unsigned char>(input[1]))) {
		return ScalarType::CHAR;
	}
	if (input == "nanf" || input == "+inff" || input == "-inff")
		return ScalarType::FLOAT;
	if (input == "nan" || input == "+inf" || input == "-inf")
		return ScalarType::DOUBLE;
	if (isValidBody(input)) {
		if (input.back() == 'f') {
			return ScalarType::FLOAT;
		} else if (input.find('.') != std::string::npos) {
			return ScalarType::DOUBLE;
		} else {
			return ScalarType::INT;
		}
	}
	return ScalarType::INVALID;
}

void ScalarConverter::convert(const std::string &input) {

	if (input.empty()) {
		throw std::invalid_argument("Input string is empty.");
	}
	ScalarType type = determineType(input);
	std::cout << "Converting input: " << input << std::endl;
	if (type != ScalarType::CHAR){
	try {
		if (std::stoi(input) < 0 || std::stoi(input) > 127)
			throw std::out_of_range("impossible");
		char c = static_cast<char>(std::stoi(input)); // Attempt to convert the input string to a char
		if (!std::isprint(c))
			throw std::invalid_argument("Non displayable");
		std::cout << "char: " << c << std::endl;
	} catch (const std::invalid_argument &e) {
			std::cout << "char: " << e.what() << std::endl;
	} catch (const std::out_of_range &e) {
	std::cout << "char: " << e.what() << std::endl;
	}}

	if (type != ScalarType::INT){
	try {
		int i = std::stoi(input); // Attempt to convert the input string to an integer
		std::cout << "Converted value to int: " << i << std::endl;
	} catch (const std::invalid_argument &e) {
		std::cout << "Invalid argument for int conversion: " << e.what() << std::endl;
	} catch (const std::out_of_range &e) {
		std::cout << "Out of range for int conversion: " << e.what() << std::endl;
	}}

	if (type != ScalarType::FLOAT){
	try {
		float f = std::stof(input); // Attempt to convert the input string to a float
		std::cout << "Converted value to float: " << f << std::endl;
	} catch (const std::invalid_argument &e) {
		std::cout << "Invalid argument for float conversion: " << e.what() << std::endl;
	} catch (const std::out_of_range &e) {
		std::cout << "Out of range for float conversion: " << e.what() << std::endl;
	}}

	if (type != ScalarType::DOUBLE){
	try {
		double d = std::stod(input); // Attempt to convert the input string to a double
		std::cout << "Converted value to double: " << d << std::endl;
	} catch (const std::invalid_argument &e) {
		std::cout << "Invalid argument for double conversion: " << e.what() << std::endl;
	} catch (const std::out_of_range &e) {
		std::cout << "Out of range for double conversion: " << e.what() << std::endl;
	}}
}