#include "Span.hpp"

Span::Span(unsigned int _N) : N(_N) {};

void Span::addNumber(unsigned int value) {
  if (span.size() < N)
    span.insert(span.begin(), value);
  else
    throw std::out_of_range("span is full :(");
}

int Span::shortestSpan() {
  if (span.size() < 2)
    throw std::exception();

  std::vector<int> sorted = span;
  std::sort(sorted.begin(), sorted.end());

  int shortest = INT_MAX;
  for (size_t i = 1; i < sorted.size(); i++) {
    int diff = sorted[i] - sorted[i - 1];
    if (diff < shortest)
      shortest = diff;
  }

  return shortest;
}
// int Span::longestSpan() {}
