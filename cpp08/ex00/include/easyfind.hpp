#pragma once
#include <ranges>
#include <iostream>
#include <stdexcept>
template <typename T>
int easyfind(T& container, const int find) {
	 if (const auto iter = std::ranges::find(container, find) ; iter != std::ranges::end(container)) {
		std::cout << "found " << find << '\n';
	} else {
		throw std::runtime_error("element " +std::to_string(find)+ " not found");
	}
	return 1;
}
