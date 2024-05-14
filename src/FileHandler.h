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
    //openFiles function takes 4 parameters: 2 ifstream references, 2 strings.
    //closeFiles function takes 2 parameters: 2 ifstream references.
public:
    static bool openFiles(std::ifstream& infile, std::ofstream& outfile, const std::string& inputFilePath, const std::string& outputFilePath);
    static void closeFiles(std::ifstream& infile, std::ofstream& outfile);
};

#endif //CS201_GRAPH_PROJECT_03_FILEHANDLER_H
