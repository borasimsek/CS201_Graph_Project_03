//
// Created by bora on 15.05.2024.
//

#include "Edge.h"

Edge::Edge(int from, int to){
    this->from = from;
    this->to = to;
    next = nullptr;
}

void Edge::setNext(Edge* edge){
    next = edge;
}
int Edge::getFrom() {
    return from;
}
int Edge::getTo() {
    return to;
}
Edge* Edge::getNext() {
    return next;
}