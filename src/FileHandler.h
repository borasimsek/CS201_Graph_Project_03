//
// Created by bora on 15.05.2024.
//

#ifndef CS201_GRAPH_PROJECT_03_FILEHANDLER_H
#define CS201_GRAPH_PROJECT_03_FILEHANDLER_H

#include <fstream>
#include <string>

class FileHandler {
    //The aim of this class is to handle file operations.
    //openFiles function opens the input and output files.
    //closeFiles function closes the input and output files.
    //openFiles function returns true if both files are opened successfully.
    //closeFiles function does not return anything.
public:
    static bool openFiles(std::ifstream& inputFile, std::ofstream& outputFile, const std::string& FilePathInput, const std::string& FilePathOutput);
    static void closeFiles(std::ifstream& infile, std::ofstream& outfile);
};

#endif //CS201_GRAPH_PROJECT_03_FILEHANDLER_H
