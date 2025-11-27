#include "ScalarConverter.hpp"
#include <exception>
#include <stdexcept>

ScalarConverter::ScalarConverter() {};

ScalarConverter::~ScalarConverter() {};

float convert_int(const std::string& input) {
	(void)input;
	return 0;
}
int check_type(const std::string& str) {

	const std::regex charRegex("^[^0-9]$");
	const std::regex intRegex("^[-+]?[0-9]+$");
	const std::regex doubleRegex(R"(^[-+]?\d*\.?\d+([eE][-+]?\d+)?$)");
	const std::regex floatRegex("^[-+]?([0-9]+[.][0-9]+|(inf|nan))?f$");

	if (std::regex_match(str, charRegex)) {
		std::cout << str << " is a char\n";
		return CHAR;
	} else if (std::regex_match(str, intRegex)) {
		std::cout << str << " is an integer\n";
		return INT;
	} else if (std::regex_match(str, floatRegex)) {
		std::cout << str << " is a float\n";
		return FLOAT;
	} else if (std::regex_match(str, doubleRegex)) {
		std::cout << str << " is a double\n";
		return DOUBLE;
	}
	std::cout << str << " is not a number\n";
	return INVALID;
}

std::ostream& convert_to_char(std::ostream& os, const std::string& str) {
	char c;
	c = std::stoi(str);
	if (c < 32) {
		os << "Char: Non displayable";
		return os;
	}
	os << "Char: " << c;
	return os;
}

void ScalarConverter::convert(const std::string& str) {
	unsigned int type = check_type(str);
	try {
		convert_to_char(std::cout, str) << '\n';
	} catch (const std::invalid_argument& e) {
		std::cout << "invalid argument!" << '\n';
		return ;
	}
	std::cout << "char:   " << '\n';
	std::cout << "int:    " << '\n';
	std::cout << "float:  " << '\n';
	std::cout << "double: " << '\n';
}
