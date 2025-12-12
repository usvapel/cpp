
#include <iostream>
#include <ranges>
#include <stdexcept>

template <typename T> void easyfind(T &container, const int subvalue) {
  auto it = std::ranges::find(container, subvalue);
  if (it != container.end()) {
    auto index = it - container.begin();
    std::cout << "found " << subvalue << " at index: [" << index << "]" << '\n';
  } else {
    throw std::runtime_error("element " + std::to_string(subvalue) +
                             " not found");
  }
}
