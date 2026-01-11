#include "PmergeMe.hpp"

// generate weird jacob insertion order
static std::deque<int> generateInsertionOrder(size_t pairCount) {
  if (pairCount == 0)
    return {};

  // jacobshtal numbers
  std::deque<int> jacob;
  jacob.push_back(0);
  jacob.push_back(1);
  while (jacob.back() < (int)pairCount) {
    int n = jacob.size();
    jacob.push_back(jacob[n - 1] + 2 * jacob[n - 2]);
  }

  std::deque<int> order;
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

void mergeInsertionSortDeque(std::deque<int> &vec) {

  // create pairs with larger element first
  std::deque<std::pair<int, int>> pairs;
  for (size_t i = 0; i + 1 < vec.size(); i += 2) {
    int a = vec[i];
    int b = vec[i + 1];
    if (a > b)
      pairs.emplace_back(a, b);
    else
      pairs.emplace_back(b, a);
  }

  std::sort(pairs.begin(), pairs.end());

  // containers for big and small values each
  std::deque<int> biggerValues;
  std::deque<int> smallerValues;
  for (const auto &[first, second] : pairs) {
    biggerValues.push_back(first);
    smallerValues.push_back(second);
  }

  // generate Jacobsthal numbers
  std::deque<int> insertOrder;
  insertOrder = generateInsertionOrder(pairs.size());

  // insert smaller values to the main chain with big values
  for (size_t i : insertOrder) {
    int value = smallerValues[i];
    auto start = biggerValues.begin();
    auto end = biggerValues.end();
    // binary search, returns iterator to first position where value can be
    // inserted while keeping it sorted
    auto pos = std::lower_bound(start, end, value);
    biggerValues.insert(pos, value);
  }

  // check if theres an odd amount of values
  if (vec.size() % 2 != 0) {
    auto start = biggerValues.begin();
    auto end = biggerValues.end();
    auto pos = std::lower_bound(start, end, vec.back());
    biggerValues.insert(pos, vec.back());
  }

  vec = biggerValues;
}
