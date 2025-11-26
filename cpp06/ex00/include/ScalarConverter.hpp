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

	template < typename T >
	static void convert(const T& input);
};
