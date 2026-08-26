#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <input_string>" << std::endl;
		return 1;
	}
	std::string input = argv[1];
	try{
		ScalarConverter::convert(input);
	} catch (const std::exception &e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
	return 0;
}
