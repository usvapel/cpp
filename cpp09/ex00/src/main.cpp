#include "BitcoinExchange.hpp"

std::optional<std::string> validate_date(std::string &line) {
  std::istringstream ss{line};
  std::chrono::year_month_day ymd;
  ss >> std::chrono::parse("%Y-%m-%d", ymd);
  if (ss.fail())
    return std::nullopt;
  else
    return line.substr(0, line.find('|') - 1);
}

void validate_inputfile(std::string inputfile,
                        std::map<std::string, double> csv_map) {
  std::ifstream file(inputfile);
  if (!file.is_open()) {
    std::cout << "error opening file " << inputfile << '\n';
    return;
  }

  std::string line;

  getline(file, line);
  while (getline(file, line)) {
    if (line.empty()) {
      continue;
    }

    if (!std::regex_search(line, inputfileregex)) {
      std::cout << "\e[1;91m Error:\e[0;37m bad input => " << line << '\n';
      continue;
    }

    std::optional<std::string> date = validate_date(line);
    if (!date.has_value()) {
      std::cout << "Error: bad input => " << line << '\n';
      continue;
    }

    std::optional<std::string> btc = line.substr(line.find('|') + 1);
    if (!btc.has_value()) {
      continue;
    }

    auto it = csv_map.lower_bound(date.value());
    if (it != csv_map.end() && it->first == date.value()) {
    } else if (it == csv_map.begin()) {
      ++it;
    } else {
      --it;
    }

    std::cout << date.value() << " =>" << btc.value() << " = "
              << std::stod(btc.value()) * it->second << '\n';
  }

  file.close();
  return;
}

std::map<std::string, double> parse_csv() {
  std::ifstream csv_file("data.csv");
  std::string line;
  std::map<std::string, double> csv_data;

  while (getline(csv_file, line)) {
    if (!std::regex_search(line, csvregex)) {
      continue;
    }
    std::string date = line.substr(0, line.find(','));
    double btc = (std::stod(line.substr(line.find(',') + 1, line.back())));
    csv_data.insert(std::make_pair(date, btc));
  }

  csv_file.close();
  return csv_data;
}

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "error: single input file required!" << '\n';
    return 0;
  }
  std::map<std::string, double> csv_map = parse_csv();
  validate_inputfile(av[1], csv_map);
}
