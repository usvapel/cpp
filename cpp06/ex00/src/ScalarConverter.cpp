#include "ScalarConverter.hpp"

const std::regex charRegex("^[^0-9]$");
const std::regex intRegex("[-+]?[0-9]+[^.]?+");
const std::regex floatRegex("[-+]?([0-9]+[.][0-9]+|(inf|nan))f");
const std::regex doubleRegex("[-+]?([0-9]+[.][0-9]+|(inf|nan))");
const std::regex specialRegex("[-+]?(inf|nan)f?");

std::optional<char> convert_to_char(const std::string &literal) {
  return std::make_optional<char>(literal[0]);
}

std::optional<int> convert_to_int(const std::string &literal) {
  return std::make_optional<int>(std::stoi(literal));
}

std::optional<float> convert_to_float(const std::string &literal) {
  return std::make_optional<float>(std::stof(literal));
}

std::optional<double> convert_to_double(const std::string &literal) {
  return std::make_optional<double>(std::stod(literal));
}
// done
std::ostream &char_conversion(std::ostream &os, std::optional<char> literal) {
  os << "char\n";
  return os << "char: " << *literal << '\n'
            << "int: " << static_cast<int>(*literal) << '\n'
            << "float: " << static_cast<float>(*literal) << ".0f" << '\n'
            << "double: " << static_cast<double>(*literal) << ".0" << '\n';
}
// done
std::ostream &int_conversion(std::ostream &os, std::optional<int> literal) {

  os << "int\n";
  return os << "char: "
            << (*literal < 255 && std::isprint(*literal)
                    ? std::string(1, static_cast<char>(*literal))
                    : "impossible")
            << '\n'
            << "int: " << *literal << '\n'
            << "float: " << *literal << ".0f" << '\n'
            << "double: " << *literal << ".0" << '\n';
}

std::ostream &float_conversion(std::ostream &os, std::optional<float> literal) {
  os << "float\n";
  return os << "char: "
            << (*literal >= 0 && *literal < 128 &&
                        std::isprint(static_cast<int>(*literal))
                    ? std::string(1, static_cast<char>(*literal))
                    : "impossible")
            << '\n'
            << "int: " << static_cast<int>(*literal) << '\n'
            << "float: " << *literal
            << (std::trunc(*literal) != *literal ? "f" : ".0f") << '\n'
            << "double: " << *literal
            << (std::trunc(*literal) != *literal ? "" : ".0") << '\n';
}

std::ostream &double_conversion(std::ostream &os,
                                std::optional<double> literal) {
  os << "double\n";
  return os << "char: "
            << (*literal < 255 && std::isprint(*literal)
                    ? std::string(1, static_cast<char>(*literal))
                    : "impossible")
            << '\n'
            << "int: " << static_cast<int>(*literal) << '\n'
            << "float: " << *literal
            << (std::trunc(*literal) != *literal ? "f" : ".0f") << '\n'
            << "double: " << *literal
            << (std::trunc(*literal) != *literal ? "" : ".0") << '\n';
}

void ScalarConverter::convert(const std::string &literal) {

  // detect type
  int type = std::regex_match(literal, charRegex)     ? CHAR
             : std::regex_match(literal, intRegex)    ? INT
             : std::regex_match(literal, floatRegex)  ? FLOAT
             : std::regex_match(literal, doubleRegex) ? DOUBLE
                                                      : INVALID;
  std::optional<char> char_literal;
  std::optional<int> int_literal;
  std::optional<float> float_literal;
  std::optional<double> double_literal;

  // convert to type
  switch (type) {

  case CHAR:
    char_literal = convert_to_char(literal);
    break;

  case INT:
    try {
      int_literal = convert_to_int(literal);
    } catch (const std::out_of_range &e) {
      std::cout << "value out of range!" << '\n';
    }
    break;

  case FLOAT:
    float_literal = convert_to_float(literal);
    break;

  case DOUBLE:
    double_literal = convert_to_double(literal);
    break;

  case INVALID:
    std::cout << "<" << literal << "> invalid input\n";
    return;
  }
  // convert to all other types.. what is wrong with this subject wth..
  if (char_literal.has_value())
    char_conversion(std::cout, char_literal);
  if (int_literal.has_value())
    int_conversion(std::cout, int_literal);
  if (float_literal.has_value())
    float_conversion(std::cout, float_literal);
  if (double_literal.has_value())
    double_conversion(std::cout, double_literal);
}
