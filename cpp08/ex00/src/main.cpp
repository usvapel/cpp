#include "easyfind.hpp"
#include <array>
#include <iostream>

int main() {
	std::array<int, 10> ar = {6,3,8,4,7,10,9,2,1,5};
	for (int i = 0; i < static_cast<int>(ar.size()); i++)
		std::cout << ar.at(i) << " ";
	std::cout << '\n';

	try {
		::easyfind(ar, 0); 
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << '\n';
	}

	try {
		::easyfind(ar, 5); 
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << '\n';
	}
}
