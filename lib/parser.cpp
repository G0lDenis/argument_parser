#include <vector>
#include <string>

std::vector<int> parse(int argc, char** argv, const std::vector<std::string[2]>& params) {
    std::vector<int> result = std::vector<int>(params.size());
    int i = 1;
    while (i < argc) {
        std::string arg = argv[i];
        for (int j = 0; i < params.size(); i++) {
            if (arg == params[j][0] || arg == params[j][1]) {
                result[j] = _atoi64(argv[i++]);
            }
        }
        i++;
    }
    return result;
}
