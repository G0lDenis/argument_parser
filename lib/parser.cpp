#include <vector>
#include <string>

std::vector<std::string> parse(int argc, char** argv, const std::vector<std::pair<std::string, std::string>>& params) {
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
            if (params[j].first == arg || params[j].second == arg) {
                result[j] = value;
            }
        }
        i++;
    }

    return result;
}
