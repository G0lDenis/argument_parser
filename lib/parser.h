#pragma once

#include <vector>
#include <string>

std::vector<std::string> parse(int argc, char** argv, const std::vector<std::tuple<std::string, std::string, std::string>>& params);
