//
// Created by bora on 15.05.2024.
//

#ifndef CS201_GRAPH_PROJECT_03_EDGE_H
#define CS201_GRAPH_PROJECT_03_EDGE_H


class Edge{
private:
    int from;
    int to;
    Edge* next;
public:
    Edge(int from, int to);
    void setNext(Edge* edge);
    int getFrom();
    int getTo();
    Edge* getNext();
};
#endif //CS201_GRAPH_PROJECT_03_EDGE_H
