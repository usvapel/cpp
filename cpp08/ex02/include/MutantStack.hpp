#pragma once

#include <iostream>
#include <stack>

template <typename T, class Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
public:
  MutantStack() = default;
  MutantStack(const MutantStack &obj) = default;
  MutantStack &operator=(const MutantStack &obj) = default;
  ~MutantStack() = default;

  using iterator = typename Container::iterator;
  using const_iterator = typename Container::const_iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }

  const_iterator begin() const { return this->c.begin(); }
  const_iterator end() const { return this->c.end(); }
  const_iterator cbegin() const { return this->c.cbegin(); }
  const_iterator cend() const { return this->c.cend(); }
};
