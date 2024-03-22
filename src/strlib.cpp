// strlib.cpp
#include "strlib.h"
#include <sstream>
#include <vector>
#include <string>

std::vector<std::string> strSplit(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}




