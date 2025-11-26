#pragma once

#include <iostream>

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
