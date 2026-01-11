#include "PmergeMe.hpp"

template <typename Container = std::vector<int>>
Container validate_input(char **input) {
  Container c;
  while (*input) {
    int index = 0;
    try {
      index = std::stoi(*input++);
    } catch (std::exception &) {
      std::cout << "Error: invalid value" << '\n';
      exit(1);
    }
    if (index < 0) {
      std::cout << "Error: value is negative" << '\n';
      exit(1);
    }
    c.push_back(index);
  }
  return c;
}

int main(int ac, char **av) {
  if (ac == 1) {
    std::cout << "Error" << '\n';
    return 0;
  }

  auto vec = validate_input(av + 1);
  auto deq = validate_input<std::deque<int>>(av + 1);

  const size_t max_display = 10;

  std::cout << "before:  ";
  for (size_t i = 0; i < vec.size() && i < max_display; i++) {
    std::cout << vec[i] << ' ';
  }
  if (vec.size() > max_display)
    std::cout << "[...]";
  std::cout << '\n';

  {
    SortBenchmark benchmark(vec, mergeInsertionSortVector, 10000);
    auto avg_time = benchmark.run(vec);

    std::cout << "after:   ";
    for (size_t i = 0; i < vec.size() && i < max_display; i++) {
      std::cout << vec[i] << ' ';
    }
    if (vec.size() > max_display)
      std::cout << "[...]";
    std::cout << '\n';

    std::cout << "Time to process a range of [" << ac - 1
              << "] elements with std::vector : " << avg_time << '\n';
  }
  {
    SortBenchmark benchmark(deq, mergeInsertionSortDeque, 10000);
    auto avg_time = benchmark.run(deq);
    std::cout << "Time to process a range of [" << ac - 1
              << "] elements with std::vector : " << avg_time << '\n';
  }
  return 0;
}
