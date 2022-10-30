#include <vector>
#include <string>
#include <tuple>

std::vector<std::string>
parse(int argc, char** argv, const std::vector<std::tuple<std::string, std::string, std::string>>& params) {
	std::vector<std::string> result = std::vector<std::string>(params.size());
	int i = 1;
	while (i < argc) {
		std::string arg = argv[i];
		auto eq = arg.find('=');
		std::string value;
		if (eq == -1) {
			value = argv[++i];
		} else {
			value = arg.substr(eq + 1, arg.length() - eq - 1);
			arg = arg.substr(0, eq);
		}

		for (int j = 0; j < params.size(); j++) {
			if (std::get<0>(params[j]) == arg || std::get<1>(params[j]) == arg) {
				result[j] = value;
			}
		}
		i++;
	}
	for (int j = 0; j < argc; j++) {
		if (result[j].empty()) {
			result[j] = std::get<2>(params[j]);
		}
	}

	return result;
}
