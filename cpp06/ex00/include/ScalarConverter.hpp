#pragma once

#include <iostream>
#include <optional>
#include <regex>
#include <cmath>
#include <limits.h>

enum e {
  CHAR,
  INT,
  FLOAT,
  DOUBLE,
  INVALID,
};

class ScalarConverter {
public:
  ScalarConverter() = delete;
  ScalarConverter(const ScalarConverter &obj) = delete;
  ScalarConverter operator=(const ScalarConverter &obj) = delete;
  ~ScalarConverter() = default;

  static void convert(const std::string &);
};
