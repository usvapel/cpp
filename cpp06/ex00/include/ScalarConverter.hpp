#pragma once

#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <regex>

enum e {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID,
};

class ScalarConverter
{
  private:
	ScalarConverter();

  public:
	ScalarConverter(const ScalarConverter &obj) = delete;
	ScalarConverter operator=(const ScalarConverter &obj) = delete;
	~ScalarConverter();

	static void convert(const std::string& input);
};
