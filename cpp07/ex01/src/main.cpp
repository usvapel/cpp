#include "Iter.hpp"

void test_int_array_increment() {
  int numbers[] = {1, 2, 3, 4, 5};
  size_t length = 5;

  print_array("Before", numbers, length);
  iter(numbers, length, [](int &n) { n += 10; });
  print_array("After", numbers, length);
  std::cout << std::endl;
}

void test_string_array_uppercase() {
  std::string words[] = {"hello", "world", "test", "case"};
  size_t length = 4;

  print_array("Before", words, length);
  iter(words, length, [](std::string &str) {
    for (char &c : str) {
      c = std::toupper(c);
    }
  });
  print_array("After", words, length);
  std::cout << std::endl;
}

int main() {
  test_int_array_increment();
  test_string_array_uppercase();
  return 0;
}
