//
// Created by bora on 15.05.2024.
//

#include "Graph.h"

#include "Graph.h"

using namespace std;

Graph::Graph(int vertexCount){
    this->vertexCount = vertexCount;
    edges = new EdgeList[vertexCount];
    for (int i=0; i<vertexCount; i++)
        edges[i] = EdgeList();
}

Graph::~Graph(){
    delete [] edges;
}

void Graph::addEdge(int from, int to) {
    Edge *edge = new Edge(from, to);
    edges[from].insert(edge);
}

EdgeList* Graph::getEdgelist(int vertex) const {
    if (vertex < 0 || vertex >= vertexCount) {
        return nullptr; // Return null for invalid vertex index
    }
    return &edges[vertex];
}
