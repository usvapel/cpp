#pragma once

#include <iostream>

template <typename T>
class MutantStack {
private:
public:
  MutantStack();
  MutantStack(const MutantStack &obj);
  MutantStack &operator=(const MutantStack &obj);

  void push();
  void pop();
  void top();
  int size();
  int begin();
  int end();

  static T iterator(T val) {
		return this->;
	}
  ~MutantStack() = default;
};
