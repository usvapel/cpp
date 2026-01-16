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
// class for benchmarking the sorting
template <typename Container, typename SortFunc> class SortBenchmark {
  const Container &original_;
  SortFunc sort_func_;
  int iterations_;
  size_t comparisons_;

public:
  SortBenchmark(const Container &data, SortFunc func, int iterations = 10000)
      : original_(data), sort_func_(func), iterations_(iterations),
        comparisons_(0) {}

  void is_sorted(const Container &c) {
    if (std::ranges::is_sorted(c))
      std::cout << "sorted!" << '\n';
  }

  auto run() {
    const size_t max_display = 10;

    std::cout << "before:  ";
    for (size_t i = 0; i < original_.size() && i < max_display; i++) {
      std::cout << original_[i] << ' ';
    }
    if (original_.size() > max_display)
      std::cout << "[...]";
    std::cout << '\n';

    auto start = std::chrono::steady_clock::now();

    Container output = original_;
    for (int i = 0; i < iterations_; ++i) {
      comparison_count = 0;
      output = original_;
      output = sort_func_(output);
      comparisons_ += comparison_count;
    }

    auto finish = std::chrono::steady_clock::now();

    std::cout << "after:   ";
    for (size_t i = 0; i < output.size() && i < max_display; i++) {
      std::cout << output[i] << ' ';
    }

    if (output.size() > max_display)
      std::cout << "[...]";
    std::cout << '\n';

    auto avg_time =
        std::chrono::duration<double, std::micro>(finish - start) / iterations_;

    comparisons_ = comparisons_ / iterations_;
    std::cout << "operations: " << comparisons_ << '\n';
    std::cout << "Time to process a range of [" << output.size()
              << "] elements with std::vector : " << avg_time << '\n';

    is_sorted(output);
  }
};

std::vector<int> mergeInsertionSortVector(std::vector<int> &vec);
std::deque<int> mergeInsertionSortDeque(std::deque<int> &deq);
