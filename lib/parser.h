#pragma once

#include <vector>
#include <string>
#include <any>

void PutValue(const std::any& variable, const std::any& value);

void Parse(int argc, char** argv,
		   const std::vector<std::tuple<void*, std::string&, std::string&>>& params,
		   std::vector<std::string>& args);
