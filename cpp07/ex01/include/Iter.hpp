#pragma once

#include <cstddef>
#include <iostream>

template <typename T, typename Func>
void iter(T *array, const size_t length, Func f) {
  for (size_t i = 0; i < length; i++) {
    f(array[i]);
  }
}

template <typename T>
void print_array(const std::string label, T *array, size_t length) {
  std::cout << label << ": ";
  for (size_t i = 0; i < length; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << '\n';
}
