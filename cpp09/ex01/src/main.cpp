#include "Span.hpp"
#include <array>

int main() {
  {
    srand(time(0));
    Span sp(100000);
    for (int i = 0; i < 100000; i++) {
      sp.addNumber(rand());
    }
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  {
    Span sp(100000);
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sp.addRange(numbers.begin(), numbers.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  {
    Span sp(100000);
    std::array<int, 10> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, -10};
    sp.addRange(numbers.begin(), numbers.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  {
    Span sp(1);
    std::array<int, 10> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, -10};
    try {
      sp.addRange(numbers.begin(), numbers.end());
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << '\n';
    }
  }
  return 0;
}
