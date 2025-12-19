#pragma once

#include <iostream>

template <typename T> class Array {
private:
  T *elements;
  unsigned int array_size;

public:
  Array();
  Array(unsigned int n);
  Array(const Array &obj);
  Array &operator=(const Array &obj);
  unsigned int size();
  T &operator[](const unsigned int index);
  ~Array();
};

#include "Array.tpp"
