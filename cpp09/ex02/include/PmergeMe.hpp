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

  auto run(Container &output) {
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < iterations_; ++i) {
      comparison_count = 0;
      output = original_;
      sort_func_(output);
      comparisons_ += comparison_count;
    }

    auto finish = std::chrono::steady_clock::now();
    comparisons_ = comparisons_ / iterations_;
    return std::chrono::duration<double, std::micro>(finish - start) /
           iterations_;
  }
  size_t get_comparisons() { return comparisons_; }
};

std::vector<int> mergeInsertionSortVector(std::vector<int> &vec);
std::deque<int> mergeInsertionSortDeque(std::deque<int> &deq);
