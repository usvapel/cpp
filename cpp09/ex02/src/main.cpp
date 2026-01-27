#include "PmergeMe.hpp"
#include <cstddef>
#include <optional>
#include <stdexcept>
#include <iomanip>

#define ITERATIONS 1
size_t comparison_count = 0;

void testScaling() {
  std::vector<int> sizes = {10, 50, 100, 500, 1000, 2000, 3000};

  std::cout << "n\tComparisons\tn*log2(n)\tRatio\n";
  std::cout << "-------------------------------------------\n";

  for (int n : sizes) {
    std::vector<int> data;
    for (int i = 0; i < n; i++) {
      data.push_back(rand() % 10000);
    }

    comparison_count = 0;
    mergeInsertionSortVector(data);
    size_t comps = comparison_count;

    double theoretical = n * log2(n);
    double ratio = comps / theoretical;

    std::cout << n << "\t" << comps << "\t\t" << (int)theoretical << "\t\t"
              << std::fixed << std::setprecision(3) << ratio << "\n";
  }
}

template <typename Container> Container validate_input(char **input) {
  Container c;
  while (*input) {
    int index = 0;
    try {
      index = std::stoi(*input++);
    } catch (std::exception &) {
      throw std::invalid_argument("Error: invalid value");
    }
    if (index < 0)
      throw std::invalid_argument("Error: negative value");
    c.push_back(index);
  }
  return c;
}

int main(int ac, char **av) {
  if (ac == 1) {
    std::cout << "Error" << '\n';
    return 0;
  }
  {
    try {
      std::vector<int> vec = validate_input<std::vector<int>>(av + 1);
      SortBenchmark benchmark(vec, mergeInsertionSortVector, ITERATIONS);
      benchmark.run();
    } catch (const std::invalid_argument &e) {
      std::cout << e.what() << '\n';
      return 0;
    }
  }
  {
    try {
      std::deque<int> deq = validate_input<std::deque<int>>(av + 1);
      SortBenchmark benchmark(deq, mergeInsertionSortDeque, ITERATIONS);
      benchmark.run();
    } catch (const std::invalid_argument &e) {
      std::cout << e.what() << '\n';
      return 0;
    }
  }
  std::cout << '\n';
  testScaling();
  return 0;
}
