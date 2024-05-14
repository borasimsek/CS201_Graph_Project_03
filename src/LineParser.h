//
// Created by bora on 15.05.2024.
//

#ifndef CS201_GRAPH_PROJECT_03_LINEPARSER_H
#define CS201_GRAPH_PROJECT_03_LINEPARSER_H

// LineParser.h


#include <string>

class LineParser {
    //The aim of this class is to parse lines.
    //trim function removes leading and trailing whitespaces from a string.
    //parseLine function parses a line into two strings.
    //isVariableUsed function checks if a variable is used in an expression.
    //trim function returns a string.
    //parseLine function does not return anything.
    //isVariableUsed function returns a boolean.
public:
    static std::string trim(const std::string& str);
    static void parseLine(const std::string& line, std::string& lhs, std::string& rhs);
    static bool isVariableUsed(const std::string& expression, const std::string& variable);
};


#endif //CS201_GRAPH_PROJECT_03_LINEPARSER_H
