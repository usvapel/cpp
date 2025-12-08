#include "Iter.hpp"

int to_upper_wrapper(int c) {
	return std::toupper(c);
}

int subtract(int v) {
	return v - 1;
}

int main() {
	std::string array1 = "abcdef";
	::print_array("std::string", &array1[0], 6);
	::iter(&array1[0], array1.length(), to_upper_wrapper);
	::print_array("std::string", &array1[0], 6);

	char array2[] = "abcdef";
	::print_array("char array", array2, 6);
	::iter(array2, 6, to_upper_wrapper);
	::print_array("char array", array2, 6);

	int array3[3] = {1, 2, 3};
	::print_array("int array", array3, 3);
	::iter(array3, 3, subtract);
	::print_array("int array", array3, 3);
}
