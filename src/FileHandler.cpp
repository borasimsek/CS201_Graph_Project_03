//
// Created by bora on 15.05.2024.
//

#include "FileHandler.h"

bool FileHandler::openFiles(std::ifstream& inputFile, std::ofstream& outputFile, const std::string& FilePathInput, const std::string& FilePathOutput) {
    inputFile.open(FilePathInput);
    outputFile.open(FilePathOutput);
    return inputFile.is_open() && outputFile.is_open();
}

void FileHandler::closeFiles(std::ifstream& infile, std::ofstream& outfile) {
    infile.close();
    outfile.close();
}