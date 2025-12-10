#pragma once

#include <iostream>

template <typename T> class Array {
private:
  T *elements;
  int array_size;

public:
  Array();
  Array(unsigned int n);
  Array(const Array &obj);
  Array &operator=(const Array &obj);
  int size();
  T &operator[](const int index);
  ~Array();
};

#include "Array.tpp"
