#pragma once

#include <vector>
#include <string>
#include <variant>

#define supported_variants std::variant<int, bool, std::string>

void PutValue(supported_variants& variable, const std::string& value);

void Parse(int argc, char** argv,
		   std::vector<std::tuple<supported_variants&, std::string, std::string>>& params,
		   std::vector<std::string>& args);
