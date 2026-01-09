#include "PmergeMe.hpp"

std::vector<int> validate_input(char **input) {
  std::vector<int> v;
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
    v.push_back(index);
  }
  return v;
}

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

void mergeInsertionSort(std::vector<int> &v) {

  // create pairs with larger element first
  std::vector<std::pair<int, int>> pairs;
  for (size_t i = 0; i + 1 < v.size(); i += 2) {
    int a = v[i];
    int b = v[i + 1];
    if (a > b)
      pairs.emplace_back(a, b);
    else
      pairs.emplace_back(b, a);
  }

  std::sort(pairs.begin(), pairs.end());

  // vectors for big and small values each
  std::vector<int> biggerValues;
  std::vector<int> smallerValues;
  for (const auto &p : pairs) {
    biggerValues.push_back(p.first);
    smallerValues.push_back(p.second);
  }

  // generate Jacobsthal numbers
  std::vector<int> insertOrder;
  insertOrder = generateInsertionOrder(pairs.size());

  // insert smaller values to the main chain with big values
  for (size_t i : insertOrder) {
    int value = smallerValues[i];
    // binary search, returns iterator to first position where value can be
    // inserted while keeping it sorted
    auto start = biggerValues.begin();
    auto end = biggerValues.end();
    auto pos = std::lower_bound(start, end, value);
    biggerValues.insert(pos, value);
  }

  // check if theres an odd amount of values
  if (v.size() % 2 != 0) {
    auto start = biggerValues.begin();
    auto end = biggerValues.end();
    auto pos = std::lower_bound(start, end, v.back());
    biggerValues.insert(pos, v.back());
  }

  v = biggerValues;
}

int main(int ac, char **av) {
  if (ac == 1) {
    std::cout << "Error" << '\n';
    return 0;
  }

  std::vector<int> v = validate_input(av + 1);

  std::cout << "before:  ";
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << v[i] << ' ';
  }
  std::cout << '\n';

  mergeInsertionSort(v);

  std::cout << "after:   ";
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << v[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}
