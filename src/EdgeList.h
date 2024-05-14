//
// Created by bora on 15.05.2024.
//

#ifndef CS201_GRAPH_PROJECT_03_EDGELIST_H
#define CS201_GRAPH_PROJECT_03_EDGELIST_H

#include "src/Edge.h"

class EdgeList{
private:
    Edge* head;
    Edge* tail;
public:
    EdgeList ();
    void insert (Edge* newEdge);
    Edge* getHead();
    Edge* getTail();
};


#endif //CS201_GRAPH_PROJECT_03_EDGELIST_H
