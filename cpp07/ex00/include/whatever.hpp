#pragma once
#include <iostream>
// doesnt work on c++20 with the awesome class provided in the eval sheet.
// defining one special member function means the compiler generated copy constructor
// becomes deprecated in c++11

template <typename T> void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T> T &min(T &a, T &b) { return a < b ? a : b; }

template <typename T> T &max(T &a, T &b) { return a > b ? a : b; }
