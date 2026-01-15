#include "PmergeMe.hpp"
#include <map>

// generate weird jacob insertion order
std::vector<int> generateInsertionOrder(size_t pairCount) {
  if (pairCount == 0)
    return {};

  // jacobshtal numbers
  std::vector<int> jacob;
  jacob.push_back(0);
  jacob.push_back(1);
  while (jacob.back() < (int)pairCount) {
    int n = jacob.size();
    jacob.push_back(jacob[n - 1] + 2 * jacob[n - 2]);
  }

  std::vector<int> order;
  order.push_back(0);

  // generate order, skip 0, 1
  size_t i = 2;
  while (i < jacob.size()) {
    if (jacob[i - 1] >= (int)pairCount)
      break;

    int current = jacob[i];
    int prev = jacob[i - 1];

    int j = std::min(current, (int)pairCount);
    for (; j > prev; j--) {
      order.push_back(j - 1);
    }

    i++;
  }

  return order;
}

std::vector<int> mergeInsertionSortVector(std::vector<int> &vec) {
  if (vec.size() <= 1)
    return vec;

  // create pairs with larger element first
  std::vector<std::pair<int, int>> pairs;
  for (size_t i = 0; i + 1 < vec.size(); i += 2) {
    int a = vec[i];
    int b = vec[i + 1];
    pairs.emplace_back(std::max(a, b), std::min(a, b));
  }

  // extract larger elements for recursion
  std::vector<int> larger_elements;
  for (auto &p : pairs) {
    larger_elements.push_back(p.first);
  }

  // recursively sort
  larger_elements = mergeInsertionSortVector(larger_elements);

  // rebuild pairs in sorted order
  // remember which smaller goes to which larger
  std::map<int, int> larger_to_smaller;
  for (auto &p : pairs) {
    larger_to_smaller[p.first] = p.second;
  }

  std::vector<int> main_chain;
  std::vector<int> pending;
  for (int larger : larger_elements) {
    main_chain.push_back(larger);
    pending.push_back(larger_to_smaller[larger]);
  }

  // insert first pending element
  if (!pending.empty()) {
    main_chain.insert(main_chain.begin(), pending[0]);
  }

  // generate insertion order with Jacobsthal numbers
  std::vector<int> insertOrder = generateInsertionOrder(pairs.size());

  // insert smaller values to the main chain
  for (size_t i = 1; i < insertOrder.size(); i++) {
    size_t idx = insertOrder[i];
    if (idx < pending.size()) {
      int value = pending[idx];
      auto start = main_chain.begin();
      auto end = main_chain.end();
      auto pos = std::lower_bound(start, end, value);
      main_chain.insert(pos, value);
    }
  }

  // check if theres an odd amount of values
  if (vec.size() % 2 != 0) {
    auto start = main_chain.begin();
    auto end = main_chain.end();
    auto pos = std::lower_bound(start, end, vec.back());
    main_chain.insert(pos, vec.back());
  }

  vec = main_chain;
  return main_chain;
}
