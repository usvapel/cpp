#include "RPN.hpp"

double calculate(std::string input, double val1, double val2) {
  switch (input[0]) {
  case '+':
    return val2 + val1;
  case '-':
    return val2 - val1;
  case '*':
    return val2 * val1;
  case '/':
    if (val1 == 0)
      throw std::runtime_error("division by zero");
    return val2 / val1;
  default:
    throw std::runtime_error("unknown operator");
  };
}

void rpn(std::string input) {
  std::stack<double> st;
  std::optional<double> element;
  std::istringstream iss(input);
  std::string s;

  while (getline(iss, s, ' ')) {

    // check syntax with regex
    if (!std::regex_match(s, rgx)) {
      std::cout << "Error" << '\n';
      return;
    }

    // convert
    try {
      element = std::stod(s);
    } catch (std::exception &) {
    }

    // last element is a number
    if (element.has_value() && iss.eof()) {
      std::cout << "Error" << '\n';
      return;
    }

    // single number followed by operator
    if (st.size() == 1 && !element.has_value()) {
      std::cout << "Error" << '\n';
      return;
    }

    // has operator, calculate
    if (!element.has_value() && st.size() >= 2 && !st.empty()) {
      double top = st.top();
      st.pop();
      try {
        top = calculate(s, top, st.top());
      } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << '\n';
        return;
      }
      st.pop();
      st.push(top);
    }

    // element is a number, push to stack
    if (element.has_value())
      st.push(element.value());

    element.reset();
  }

  if (!st.empty())
    std::cout << "result: " << st.top() << '\n';
}

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "Error" << '\n';
    return 0;
  }
  rpn(av[1]);
  return 0;
}
