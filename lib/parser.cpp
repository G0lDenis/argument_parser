#include "parser.h"

#include <vector>
#include <string>
#include <tuple>
#include <variant>

void PutValue(supported_variants& variable, const std::string& value) {
	switch (variable.index()) {
		case 0:
			variable = stoi(value);
			break;
		case 1:
			variable = (value != "0");
			break;
		case 2:
			variable = value;
	}
}

void Parse(int argc, char** argv,
		   std::vector<std::tuple<supported_variants&, std::string, std::string>>& params,
		   std::vector<std::string>& args) {
	int i = 1;
	while (i < argc) {
		std::string arg = argv[i];
		auto eq = arg.find('=');
		std::string value;
		if (eq != std::string::npos) {
			value = arg.substr(eq + 1, arg.length() - eq - 1);
			arg = arg.substr(0, eq);
			for (auto j: params) {
				if (std::get<1>(j) == arg || std::get<2>(j) == arg) {
					PutValue(std::get<0>(j), value);
					break;
				}
			}
		} else {
			bool param_found = false;
			for (auto j: params) {
				if (std::get<1>(j) == arg || std::get<2>(j) == arg) {
					switch (std::get<0>(j).index()) {
						case 0:
							PutValue(std::get<0>(j), argv[++i]);
							break;
						case 1:
							PutValue(std::get<0>(j), "1");
							break;
						case 2:
							PutValue(std::get<0>(j), argv[++i]);
					}
					param_found = true;
					break;
				}
			}
			if (!param_found) {
				args.emplace_back(argv[i]);
			}
		}
		i++;
	}
}
