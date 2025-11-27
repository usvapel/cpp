#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	if (ac < 2)
		return 0;
	auto input = av[1];
	ScalarConverter::convert(input);
}
