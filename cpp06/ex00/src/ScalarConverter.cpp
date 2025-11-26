#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};

ScalarConverter::~ScalarConverter() {};

	template < typename T >
void ScalarConverter::convert(const T& input) {
	(void)input;
	std::cout << std::boolalpha;
}
