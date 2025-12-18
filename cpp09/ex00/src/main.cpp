#include "BitcoinExchange.hpp"
#include <chrono>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>

const std::regex csvregex("^[0-9]{4}"
                          "-"
                          "([0][1-9]|[1][0-2])"
                          "-"
                          "([0-2][0-9]|[3][0-1])"
                          ","
                          "([0]+([1][0]?{3}|[0-9]?{3})|[1][0]?{3}).?[0-9]?+$");

const std::regex inputfileregex("^[0-9]{4}"
                                "-"
                                "([0][1-9]|[1][0-2])"
                                "-"
                                "([0-2][0-9]|[3][0-1])"
                                "|"
                                "([0]+([1][0]?{3}|[0-9]?{3})|[1][0]?{3})$");

bool validate_date(std::string &line) {

  std::istringstream ss{line};
  std::chrono::year_month_day ymd;
  ss >> std::chrono::parse("%Y-%m-%d", ymd);

  if (ss.fail()) {
    std::cout << "invalid date format      | " << line << '\n';
    return false;
  } else {
    return true;
  }
}

bool validate_erate(std::string &line) {
  std::string eRate = line.substr(line.find('|') + 1);
  try {
    if (std::stoi(eRate) > 1000 || std::stoi(eRate) < 0) {
      std::cout << "invalid value | " << line << '\n';
      return false;
    }
  } catch (const std::out_of_range &e) {
    std::cout << "invalid value | " << line << '\n';
    return false;
  }
  return true;
}

bool validate_inputfile(std::string inputfile) {
  std::ifstream file(inputfile);
  if (!file.is_open()) {
    std::cout << "error opening file " << inputfile << '\n';
    return false;
  }

  std::string line;

  while (getline(file, line)) {
    if (std::regex_search(line, inputfileregex)) {
      if (validate_date(line) && validate_erate(line))
        std::cout << line << '\n';
      // data.insert(std::make_pair(line.substr(0, line.find(' ')),
      //                            std::stod(line.substr(line.find('|') +
      //                            1))));
    } else {
      std::cout << "regex error | " << line << '\n';
    }
  }

  file.close();
  return true;
}

int main(int ac, char **av) {
  if (ac < 2) {
    std::cout << "error: no input file provided!" << '\n';
    return 0;
  }
  BitcoinExchange b;
  std::ifstream csv_file("data.csv");
  std::string line;
  std::map<std::string, int> csv_data;
  while (getline(csv_file, line)) {
    // if (std::regex_search(line, csvregex)) {
    //   csv_data.insert(std::make_pair(
    //       line.substr(0, line.find(',')),
    //       std::stod(line.substr(line.find(',') + 1, line.back()))));
    // }
    if (std::regex_search(line, csvregex)) {
      std::cout << (std::stod(line.substr(line.find(',') + 1, line.back())))
                << '\n';
    }
  }
  for (auto x : csv_data) {
    std::cout << "data: " << x.first << "," << x.second << '\n';
  }
  (void)av;
  // validate_inputfile(av[1]);
}
