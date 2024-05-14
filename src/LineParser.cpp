//
// Created by bora on 15.05.2024.
//

// LineParser.cpp
#include "LineParser.h"
#include <sstream>

std::string LineParser::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

void LineParser::parseLine(const std::string& line, std::string& lhs, std::string& rhs) {
    std::stringstream ss(line);
    getline(ss, lhs, '=');
    getline(ss, rhs);
    lhs = trim(lhs);
    rhs = trim(rhs);
}
bool LineParser::isVariableUsed(const std::string& expression, const std::string& variable) {
    std::stringstream ss(expression);
    std::string token;
    while (ss >> token) {
        if (token == variable) {
            return true;
        }
    }
    return false;
}
