#include "ScalarConverter.hpp"

const std::regex charRegex("^[^0-9]$");
const std::regex intRegex("[-+]?[0-9]+");
const std::regex doubleRegex(R"(^[-+]?\d*\.?\d+([eE][-+]?\d+)?$)");
const std::regex floatRegex("^[-+]?([0-9]+[.][0-9]+|(inf|nan))?f$");

std::ostream &convert_to_char(std::ostream &os, const std::string &literal) {
  int value = 0;
  try {
    value = std::stoi(literal);
  } catch (const std::out_of_range &e) {
    std::cout << "stoi: std::out_of_range!" << '\n';
    return os;
  }
  if (value < 32 || value > 126) {
    return os << "char: Non displayable" << '\n';
  }
  char c = static_cast<char>(value);
  return os << "char: " << c << '\n';
}

std::ostream &convert_to_int(std::ostream &os, const std::string &literal) {
  std::smatch match;

  std::regex_search(literal, match, intRegex);
  return os << "int: " << match.str() << '\n';
}

std::ostream &convert_to_float(std::ostream &os, const std::string &literal) {
  return os << "float: " << literal << '\n';
}

std::ostream &convert_to_double(std::ostream &os, const std::string &literal) {
  return os << "double: " << literal << '\n';
}

void ScalarConverter::convert(const std::string &literal) {

  if (std::regex_match(literal, charRegex)) {
    std::cout << "char: " << literal << '\n';
    convert_to_int(std::cout, literal);
    convert_to_float(std::cout, literal);
    convert_to_double(std::cout, literal);

  } else if (std::regex_match(literal, intRegex)) {
    convert_to_char(std::cout, literal);
    std::cout << "int: " << literal << '\n';
    convert_to_float(std::cout, literal);
    convert_to_double(std::cout, literal);

  } else if (std::regex_match(literal, floatRegex)) {
    convert_to_char(std::cout, literal);
    convert_to_int(std::cout, literal);
    std::cout << "float: " << literal << '\n';
    convert_to_double(std::cout, literal);

  } else if (std::regex_match(literal, doubleRegex)) {
    convert_to_char(std::cout, literal);
    convert_to_int(std::cout, literal);
    convert_to_float(std::cout, literal);
    std::cout << "double: " << literal << '\n';

  } else {
    std::cout << literal << " invalid\n";
  }
}
