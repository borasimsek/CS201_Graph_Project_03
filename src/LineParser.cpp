//
// Created by bora on 15.05.2024.
//

// LineParser.cpp
#include "LineParser.h"
#include <sstream>

std::string LineParser::trim(const std::string& str_dummy) {
    size_t first = str_dummy.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str_dummy.find_last_not_of(' ');
    return str_dummy.substr(first, (last - first + 1));
}

void LineParser::parseLine(const std::string& line, std::string& left_hs, std::string& rigth_hs) {
    std::stringstream ss(line);
    getline(ss, left_hs, '=');
    getline(ss, rigth_hs);
    left_hs = trim(left_hs);
    rigth_hs = trim(rigth_hs);
}
bool LineParser::isVariableUsed(const std::string& statement, const std::string& variable) {
    std::stringstream ss(statement);
    std::string token;
    while (ss >> token) {
        if (token == variable) {
            return true;
        }
    }
    return false;
}
