#include "MutantStack.hpp"
#include <list>

int main() {
  {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    --it;
    ++it;
    while (it != ite) {
      std::cout << "stack: [" << *it << "]" << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);
    std::cout << '\n';
    const MutantStack<int> const_stack(mstack);
    auto it1 = const_stack.begin();
    auto it2 = const_stack.end();
    while (it1 != it2) {
      std::cout << "stack: [" << *it1 << "]" << std::endl;
      ++it1;
    }
  }
  std::cout << '\n';
  {
    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    mstack.push_back(3);
    std::cout << mstack.back() << std::endl;
    mstack.pop_back();
    std::cout << mstack.size() << std::endl;
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    --it;
    ++it;
    while (it != ite) {
      std::cout << "stack: [" << *it << "]" << std::endl;
      ++it;
    }
    std::list<int> s(mstack);
  }
  return 0;
}

std::cout << '\n';
{
  std::cout << "=== Test: Empty stack and edge cases ===" << std::endl;
  MutantStack<int> mstack;
  
  // Test iterators on empty stack
  std::cout << "Empty stack size: " << mstack.size() << std::endl;
  MutantStack<int>::iterator it_empty = mstack.begin();
  MutantStack<int>::iterator ite_empty = mstack.end();
  std::cout << "Empty stack iteration (should print nothing):" << std::endl;
  while (it_empty != ite_empty) {
    std::cout << "stack: [" << *it_empty << "]" << std::endl;
    ++it_empty;
  }
  
  // Test with single element
  mstack.push(42);
  std::cout << "\nSingle element - top: " << mstack.top() << std::endl;
  std::cout << "Single element - size: " << mstack.size() << std::endl;
  
  for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
    std::cout << "stack: [" << *it << "]" << std::endl;
  }
  
  // Test copy constructor
  MutantStack<int> mstack_copy(mstack);
  mstack.push(100);
  std::cout << "\nOriginal stack top after push: " << mstack.top() << std::endl;
  std::cout << "Copied stack top (should be unchanged): " << mstack_copy.top() << std::endl;
}