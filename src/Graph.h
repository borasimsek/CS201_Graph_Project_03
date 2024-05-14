//
// Created by bora on 15.05.2024.
//

#ifndef CS201_GRAPH_PROJECT_03_GRAPH_H
#define CS201_GRAPH_PROJECT_03_GRAPH_H


#include "src/EdgeList.h"


class Graph{
private:
    EdgeList* edges;
    int vertexCount;
public:
    Graph(int vertexCount);
    ~Graph();
    void addEdge(int from, int to);
    EdgeList* getEdgelist(int vertex) const;
};


#endif //CS201_GRAPH_PROJECT_03_GRAPH_H
