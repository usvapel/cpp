#pragma once

#include <algorithm>
#include <chrono>
#include <cmath>
#include <deque>
#include <exception>
#include <iostream>
#include <map>
#include <vector>

extern size_t comparison_count;

template <typename Container, typename SortFunc> class SortBenchmark {
  const Container &original_;
  SortFunc sort_func_;
  int iterations_;
  size_t comparisons_;

public:
  const size_t max_display = 10;
  SortBenchmark(const Container &data, SortFunc func, int iterations = 10000)
      : original_(data), sort_func_(func), iterations_(iterations),
        comparisons_(0) {}

  void is_sorted(const Container &c) {
    if (std::ranges::is_sorted(c))
      std::cout << "sorted!" << '\n';
  }

  void print_container(std::string text, const Container &c) {
    std::cout << text;
    for (size_t i = 0; i < c.size() && i < max_display; i++) {
      std::cout << c[i] << ' ';
    }
    if (c.size() > max_display)
      std::cout << "[...]";
    std::cout << '\n';
  }

  auto run() {

    print_container("before:  ", original_);

    auto start = std::chrono::steady_clock::now();

    Container output = original_;
    for (int i = 0; i < iterations_; ++i) {
      comparison_count = 0;
      output = original_;
      output = sort_func_(output);
      comparisons_ += comparison_count;
    }

    auto finish = std::chrono::steady_clock::now();

    print_container("after:   ", output);

    auto avg_time =
        std::chrono::duration<double, std::micro>(finish - start) / iterations_;

    std::cout << "operations: " << (comparisons_ / iterations_) << '\n';
    std::cout << "Time to process a range of [" << output.size()
              << "] elements with std::vector : " << avg_time << '\n';

    is_sorted(output);
  }
};

std::vector<int> mergeInsertionSortVector(std::vector<int> &vec);
std::deque<int> mergeInsertionSortDeque(std::deque<int> &deq);
