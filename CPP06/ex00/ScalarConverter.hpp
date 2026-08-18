#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

enum class ScalarType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

class ScalarConverter {

private:
	static ScalarType determineType(const std::string &input);
	static bool isValidBody(const std::string &body);
public:
	static void convert(const std::string &input);
	ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter &other) = delete;
	ScalarConverter &operator=(const ScalarConverter &other) = delete;
	~ScalarConverter() = delete;
};