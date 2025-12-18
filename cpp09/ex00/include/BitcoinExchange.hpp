#pragma once

#include <iostream>
#include <map>

class BitcoinExchange {
private:
  std::map<std::string, int> data;

public:
  BitcoinExchange() = default;
  BitcoinExchange(const BitcoinExchange &) = default;
  BitcoinExchange &operator=(const BitcoinExchange &) = default;
  ~BitcoinExchange() = default;

  std::map<std::string, int> &get_data() { return data; }
  void create_map(std::string);
};
