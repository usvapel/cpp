#include "PmergeMe.hpp"

bool counted_less(int a, int b) {
  comparison_count++;
  return a < b;
}

std::vector<int> generateInsertionOrder(size_t pairCount) {
  if (pairCount == 0)
    return {};

  // Generate jacobshtal numbers
  std::vector<size_t> jacob;
  jacob.push_back(0);
  jacob.push_back(1);
  while (jacob.back() < pairCount) {
    size_t n = jacob.size();
    jacob.push_back(jacob[n - 1] + 2 * jacob[n - 2]);
  }

  std::vector<int> order;

  // generate order, skip 0, 1
  for (size_t i = 2; i < jacob.size() && jacob[i - 1] < pairCount; i++) {
    size_t current = std::min(jacob[i], pairCount);
    size_t prev = jacob[i - 1];

    for (size_t j = current; j > prev; j--) {
      order.push_back(j - 1);
    }
  }

  return order;
}

std::vector<int> mergeInsertionSortVector(std::vector<int> &vec) {
  if (vec.size() <= 1)
    return vec;

  size_t pairCount = vec.size() / 2;

  // create pairs with larger element first
  std::vector<std::pair<int, int>> pairs;
  for (size_t i = 0; i < pairCount; i++) {
    int a = vec[i * 2];
    int b = vec[i * 2 + 1];
    comparison_count++;
    pairs.emplace_back(std::max(a, b), std::min(a, b));
  }

  // extract larger elements for recursion
  std::vector<int> larger_elements;
  for (auto &p : pairs) {
    larger_elements.push_back(p.first);
  }

  // recursively sort
  larger_elements = mergeInsertionSortVector(larger_elements);

  // map larger to smaller
  std::map<int, int> larger_to_smaller;
  for (auto &p : pairs) {
    larger_to_smaller[p.first] = p.second;
  }

  // build main chain and pending list
  std::vector<int> main_chain;
  std::vector<int> pending;

  for (int larger : larger_elements) {
    main_chain.push_back(larger);
    pending.push_back(larger_to_smaller[larger]);
  }

  // insert first pending Rlement
  if (!pending.empty()) {
    main_chain.insert(main_chain.begin(), pending[0]);
  }

  // generate insertion order with Jacobsthal numbers
  std::vector<int> insertOrder = generateInsertionOrder(pairCount);

  // insert smaller values to the main chain
  for (int idx : insertOrder) {
    if (idx < (int)pending.size()) {
      int value = pending[idx];
      auto pos = std::lower_bound(main_chain.begin(), main_chain.end(), value,
                                  counted_less);
      main_chain.insert(pos, value);
    }
  }

  // check if theres an odd amount of values
  if (vec.size() % 2 != 0) {
    auto pos = std::lower_bound(main_chain.begin(), main_chain.end(),
                                vec.back(), counted_less);
    main_chain.insert(pos, vec.back());
  }

  vec = main_chain;
  return main_chain;
}
