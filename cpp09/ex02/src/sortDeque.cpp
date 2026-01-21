#include "PmergeMe.hpp"

static bool counted_less(int a, int b) {
  comparison_count++;
  return a < b;
}

static std::deque<int> generateInsertionOrder(size_t pairCount) {
  if (pairCount == 0)
    return {};

  // Generate jacobshtal numbers
  std::deque<size_t> jacob{0, 1};
  while (jacob.back() < pairCount) {
    size_t n = jacob.size();
    jacob.push_back(jacob[n - 1] + 2 * jacob[n - 2]);
  }

  // generate order, skip 0, 1
  std::deque<int> order;
  for (size_t i = 2; i < jacob.size(); i++) {
    size_t current = std::min(jacob[i], pairCount);
    for (size_t j = current; j > jacob[i - 1]; j--) {
      order.push_back(j - 1);
    }
  }

  return order;
}

std::deque<int> mergeInsertionSortDeque(std::deque<int> &vec) {
  if (vec.size() <= 1)
    return vec;

  size_t pairCount = vec.size() / 2;

  // create pairs with larger element first
  std::deque<std::pair<int, int>> pairs;
  for (size_t i = 0; i < pairCount; i++) {
    int a = vec[i * 2];
    int b = vec[i * 2 + 1];
    comparison_count++;
    pairs.emplace_back(std::max(a, b), std::min(a, b));
  }

  // extract larger elements for recursion
  std::deque<int> larger_elements;
  for (auto &p : pairs) {
    larger_elements.push_back(p.first);
  }

  // recursively sort
  larger_elements = mergeInsertionSortDeque(larger_elements);

  // map larger to smaller
  std::map<int, int> larger_to_smaller;
  for (auto &p : pairs) {
    larger_to_smaller[p.first] = p.second;
  }

  // build main chain and pending list
  std::deque<int> main;
  std::deque<int> pend;

  for (int larger : larger_elements) {
    main.push_back(larger);
    pend.push_back(larger_to_smaller[larger]);
  }

  // insert first pending element, always smallest
  if (!pend.empty()) {
    main.insert(main.begin(), pend[0]);
  }

  // generate insertion order with Jacobsthal numbers
  std::deque<int> insertOrder = generateInsertionOrder(pairCount);

  // insert smaller values to the main chain
  for (int i : insertOrder) {
    if (i < static_cast<int>(pend.size())) {
      int value = pend[i];
      auto pos =
          std::lower_bound(main.begin(), main.end(), value, counted_less);
      main.insert(pos, value);
    }
  }

  // handle straggler
  if (vec.size() % 2 != 0) {
    auto pos =
        std::lower_bound(main.begin(), main.end(), vec.back(), counted_less);
    main.insert(pos, vec.back());
  }

  vec = main;
  return main;
}
