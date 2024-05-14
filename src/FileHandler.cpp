//
// Created by bora on 15.05.2024.
//

#include "FileHandler.h"

bool FileHandler::openFiles(std::ifstream& infile, std::ofstream& outfile, const std::string& inputFilePath, const std::string& outputFilePath) {
    infile.open(inputFilePath);
    outfile.open(outputFilePath);
    return infile.is_open() && outfile.is_open();
}

void FileHandler::closeFiles(std::ifstream& infile, std::ofstream& outfile) {
    infile.close();
    outfile.close();
}