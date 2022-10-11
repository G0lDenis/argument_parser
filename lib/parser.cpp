#include <vector>
#include <string>

std::vector<std::string> parse(int argc, char** argv, const std::vector<std::pair<std::string, std::string>>& params) {
    std::vector<std::string> result = std::vector<std::string>(params.size());
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        auto eq = arg.find('=');
        for (int j = 0; j < params.size(); j++) {
            if (params[j].first == arg.substr(0, eq) ||
                params[j].second == arg.substr(0, eq)) {
                result[j] = arg.substr(eq + 1, arg.length() - eq - 1);
            }
        }
    }

    return result;
}
