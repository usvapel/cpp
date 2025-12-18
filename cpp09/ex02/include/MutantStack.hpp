#pragma once

#include <iostream>
#include <stack>

template <typename T, class container = std::deque<T>>
class MutantStack : public std::stack<T> {
public:
  MutantStack() = default;
  MutantStack(const MutantStack &obj) = default;
  MutantStack &operator=(const MutantStack &obj) = default;
  ~MutantStack() = default;

  typedef typename container::iterator iterator;
  typedef typename container::const_iterator const_iterator;

  iterator begin() { return this->c.begin(); };
  iterator cbegin() { return this->c.cbegin(); };
  iterator end() { return this->c.end(); };
  iterator cend() { return this->c.cend(); };
};
