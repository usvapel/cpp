#pragma once

#include <chrono>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>
#include <optional>

const std::regex csvregex("^[0-9]{4}"
                          "-"
                          "([0][1-9]|[1][0-2])"
                          "-"
                          "([0-2][0-9]|[3][0-1])"
                          ","
                          "[0-9]+.?[0-9]?+$");

const std::regex inputfileregex("^[0-9]{4}"
                                "-"
                                "([0][1-9]|[1][0-2])"
                                "-"
                                "([0-2][0-9]|[3][0-1])"
                                " \\| "
                                "(([0-9]{1,3}(\\.[0-9]+)?|1000(\\.0+)?))$");
