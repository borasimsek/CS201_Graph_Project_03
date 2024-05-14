#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "src/Graph.h"
#include "src/LineParser.h"
#include "src/FileHandler.h"

// Main function
int main() {
    std::ifstream inputFile;
    std::ofstream outputFile;

    // I will open both input and output files, and check if they are opened successfully. I opened the files in the main function.
    if (!FileHandler::openFiles(inputFile, outputFile, "../input.txt", "../output.txt")) {
        std::cerr << "Error opening files!" << std::endl; // Print error message if files cannot be opened
        return 1; // Return with error code
    }

    //Read the number of lines from the input file and store it in numberOfLines_VertexNum
    int numberOfLines_VertexNum;
    inputFile >> numberOfLines_VertexNum;
    inputFile.ignore();

    std::string *lines = new std::string[numberOfLines_VertexNum];
    for (int i = 0; i < numberOfLines_VertexNum; i++) {
        getline(inputFile, lines[i]); // Read each line from input file
    }
    // I created a graph object with the number of lines as the number of vertices. I set the initial line number to 1.
    Graph graph(numberOfLines_VertexNum + 1);

    // Track the last definition line for each variable. I initialized all values to -1 indicating no definitions yet.
    int lastDef[26];
    std::fill_n(lastDef, 26, -1);

    std::string left_hs, right_hs; // Strings to store left-hand side and right-hand side of each line

    // Additional variable to track the indentation level for if statements
    int indentationLevel = 0;

    // Loop through each line in the input file , starting from 1 (adjusting for 0-based indexing)
    for (int i = 1; i <= numberOfLines_VertexNum; i++) {
        LineParser::parseLine(lines[i - 1], left_hs, right_hs);
        // Calculate the index of the variable. I assumed that the variable is a single lowercase letter.
        // The reason 'a' is subtracted from the first character of the left-hand side is to get the index
        // of the variable.
        // By subtracting 'a' from the first character of the left-hand side, I can get the index of the variable.

        int varIndex = left_hs[0] - 'a';
        lastDef[varIndex] = i;


        if (left_hs.find("if") != std::string::npos) {
            // Add self-dependency for the if condition line
            graph.addEdge(i, i);

            // Check each variable in the expression on the right-hand side for dependencies
            std::stringstream ss(right_hs);
            std::string token;
            while (ss >> token) {
                if (std::isalpha(token[0]) && token.length() == 1) { // Ensure it's a single letter variable
                    int depIndex = token[0] - 'a'; // Calculate the index of the dependent variable
                    if (lastDef[depIndex] != -1 && lastDef[depIndex] != i) {
                        graph.addEdge(lastDef[depIndex], i); // Add edge if dependency exists
                    }
                }
            }

            // Increase the indentation level
            indentationLevel++;
        }
        if (left_hs.find("while") != std::string::npos) {
            // Add self-dependency for the while condition line
            graph.addEdge(i, i);

            // Check each variable in the expression on the right-hand side for dependencies
            std::stringstream ss(right_hs);
            std::string token;
            while (ss >> token) {
                if (std::isalpha(token[0]) && token.length() == 1) { // Ensure it's a single letter variable
                    int depIndex = token[0] - 'a'; // Calculate the index of the dependent variable
                    if (lastDef[depIndex] != -1 && lastDef[depIndex] != i) {
                        graph.addEdge(lastDef[depIndex], i); // Add edge if dependency exists
                    }
                }
            }

            // Increase the indentation level
            indentationLevel++;
        }

        if (indentationLevel > 0 && lines[i - 1].find("\t") == 0) { // Adjusting for 0-based indexing
            // If inside the if block, add self-dependency
            graph.addEdge(i, i);
        }


        if (LineParser::isVariableUsed(right_hs, left_hs)) {
            graph.addEdge(i, i); // Add self-dependency if variable used in the expression
        }

        // Check each variable in the expression on the right-hand side for dependencies
        std::stringstream ss(right_hs);
        std::string token;
        while (ss >> token) {
            if (std::isalpha(token[0]) && token.length() == 1) { // Ensure it's a single letter variable
                int depIndex = token[0] - 'a'; // Calculate the index of the dependent variable
                if (lastDef[depIndex] != -1 && lastDef[depIndex] != i) {
                    graph.addEdge(lastDef[depIndex], i); // Add edge if dependency exists
                }
            }
        }
    }

    // Write the number of lines to the output file, it is always same with VertexNum
    outputFile << numberOfLines_VertexNum << std::endl;

    int edgeCount = 0; // Variable to store the total number of edges in the graph
    // Loop through each vertex. I started from 1 (adjusting for 0-based indexing). I calculated the total number of edges.
    for (int i = 1; i <= numberOfLines_VertexNum; i++) {
        Edge *edge = graph.getEdgelist(
                i)->getHead();
        while (edge) {
            edgeCount++;
            edge = edge->getNext();
        }
    }
    outputFile << edgeCount << std::endl;

    // Loop through each vertex. I started from 1 (adjusting for 0-based indexing). I wrote the edges to the output file.
    for (int i = 1; i <= numberOfLines_VertexNum; i++) { // Starting from 1
        Edge *edge = graph.getEdgelist(
                i)->getHead();
        while (edge) {
            outputFile << edge->getFrom() << " " << edge->getTo() << std::endl;
            edge = edge->getNext();
        }
    }

    delete[] lines; // Free memory allocated for lines array
    FileHandler::closeFiles(inputFile, outputFile); // Close input and output files

    return 0;
}