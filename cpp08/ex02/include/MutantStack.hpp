#pragma once

#include <iostream>

class MutantStack {
private:
public:
  MutantStack();
  MutantStack(const MutantStack &obj);
  MutantStack &operator=(const MutantStack &obj);

  push();
  pop();
  top();
  size();
  begin();
  end();

  ~MutantStack() = default;
};
