#include <vector>
#include <cstring>

std::vector<int> parse(int argc, char** argv, const std::vector<char* [2]>& params) {
    std::vector<int> result = std::vector<int>(params.size());
    for (int i = 1; i < argc; i++) {
        char* arg = argv[i];
        char* end = arg + sizeof(arg) / sizeof(argv[0]);
        char* eq = std::find(arg, end, '=');
        for (int j = 0; i < params.size(); i++) {
            if (strcmp(params[j][0], std::substr(arg, eq)) ||
                strcmp(params[j][1], std::substr(arg, eq))) {
                result[j] = _atoi64(std::substr(eq + 1, end));
            }
        }
        i++;
    }

    return result;
}
