#pragma once

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

class Span {
private:
  unsigned int N;
  std::vector<int> span;

public:
  Span() = delete;
  Span(unsigned int);
  Span(const Span &obj) = delete;
  Span &operator=(const Span &obj) = delete;
  ~Span() = default;

  void addNumber(unsigned int);
  int shortestSpan();
  int longestSpan();
  template <typename I> void addRange(I begin, I end) {
    for (I it = begin; it != end; ++it) {
      addNumber(*it);
    }
  }
};
