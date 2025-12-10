#pragma once

#include <iostream>

template <typename T> class Array {
private:
  T *elements;

public:
  Array();
  Array(unsigned int n);
  Array(const Array &obj);
  Array &operator=(const Array &obj);
  ~Array();
};
