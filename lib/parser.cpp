#include <vector>
#include <string>
#include <tuple>
#include <any>

void PutValue(const std::any& variable, const std::any& value) {
	if (typeid(variable) == typeid(std::string*)) {
		*std::any_cast<std::string*>(variable) = std::any_cast<std::string>(value);
	} else if (typeid(variable) == typeid(int*)) {
		*std::any_cast<int*>(variable) = std::any_cast<int>(value);
	} else if (typeid(variable) == typeid(bool*)) {
		*std::any_cast<bool*>(variable) = std::any_cast<bool>(value);
	}
}

void Parse(int argc, char** argv,
		   const std::vector<std::tuple<void*, std::string&, std::string&>>& params,
		   std::vector<std::string>& args) {
	std::vector<std::string> result = std::vector<std::string>(params.size());
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
					PutValue(std::get<0>(j), 1);
					param_found = true;
					break;
				}
			}
			if (!param_found && i + 1 < argc) {
				for (auto j: params) {
					if (std::get<1>(j) == arg || std::get<2>(j) == arg) {
						PutValue(std::get<0>(j), argv[++i]);
						break;
					}
				}
			}
			else {
				args.emplace_back(argv[i]);
			}
		}
		i++;
	}
}
