#include "strlib.h"
#include <sstream>

std::vector<std::string> strSplit(const std::string& str, char splitChar) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;

    while (getline(ss, item, splitChar)) {
        result.push_back(item);
    }

    return result;
}
