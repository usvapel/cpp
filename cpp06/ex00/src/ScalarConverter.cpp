#include "ScalarConverter.hpp"

const std::regex charRegex("^[^0-9]$");
const std::regex intRegex("[-+]?[0-9]+");
const std::regex floatRegex("[-+]?([0-9]+[.][0-9]+|(inf|nan))f");
const std::regex doubleRegex("[-+]?([0-9]+[.][0-9]+|(inf|nan))");

std::ostream &convert_to_char(std::ostream &os, const std::string &literal) {
  // some bullshit
  unsigned value = (literal.size() == 1 && !std::isdigit(literal[0]))
                       ? literal[0]
                       : std::stoi(literal);
  if (value < 32 || value > 126)
    return os << "char: Non displayable" << '\n';
  return os << "char: '" << static_cast<char>(value) << "'" << '\n';
}

std::ostream &convert_to_int(std::ostream &os, const std::string &literal) {
  std::smatch match;

  if (std::regex_search(literal, match, intRegex))
    return os << "int: " << match.str() << '\n';
  // for non digit literals
  return os << "int: " << static_cast<int>(literal[0]) << '\n';
}

std::ostream &convert_to_float(std::ostream &os, const std::string &literal) {
  std::smatch match;

  if (std::regex_search(literal, match, charRegex))
    return os << "float: " << static_cast<int>(literal[0]) << ".0f" << '\n';
  if (std::regex_search(literal, match, intRegex))
    return os << "float: " << match.str().append(".0f") << '\n';
  if (std::regex_search(literal, match, floatRegex))
    return os << "float: " << match.str() << '\n';
  if (std::regex_search(literal, match, doubleRegex))
    return os << "float: " << match.str().append("f") << '\n';
  return os;
}

std::ostream &convert_to_double(std::ostream &os, const std::string &literal) {
  return os << "double: " << literal << '\n';
}

void ScalarConverter::convert(const std::string &literal) {
  int type;

  type = std::regex_match(literal, charRegex)     ? CHAR
         : std::regex_match(literal, intRegex)    ? INT
         : std::regex_match(literal, floatRegex)  ? FLOAT
         : std::regex_match(literal, doubleRegex) ? DOUBLE
                                                  : INVALID;

  if (type == INVALID) {
    std::cout << literal << " invalid\n";
    return;
  }

  convert_to_char(std::cout, literal, type);
  convert_to_int(std::cout, literal, type);
  convert_to_float(std::cout, literal, type);
  convert_to_double(std::cout, literal, type);
}
