#pragma once

#include <algorithm>
#include <chrono>
#include <deque>
#include <exception>
#include <iostream>
#include <vector>

// class for benchmarking the sorting
template <typename Container, typename SortFunc> class SortBenchmark {
  const Container &original_;
  SortFunc sort_func_;
  int iterations_;

public:
  SortBenchmark(const Container &data, SortFunc func, int iterations = 10000)
      : original_(data), sort_func_(func), iterations_(iterations) {}

  auto run(Container &output) {
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < iterations_; ++i) {
      output = original_;
      sort_func_(output);
    }

    auto finish = std::chrono::steady_clock::now();
    return std::chrono::duration<double, std::micro>(finish - start) /
           iterations_;
  }
};

void mergeInsertionSortVector(std::vector<int> &vec);
void mergeInsertionSortDeque(std::deque<int> &deq);
