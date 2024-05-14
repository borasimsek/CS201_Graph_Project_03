//
// Created by bora on 15.05.2024.
//

#include "EdgeList.h"

EdgeList::EdgeList(){
    head = nullptr;
    tail = nullptr;
}
void EdgeList::insert(Edge* newEdge){
    if (head == nullptr) {
        head = newEdge;
    }
    else{
        tail->setNext(newEdge);
    }
    tail = newEdge;
}

Edge* EdgeList::getHead(){
    return head;
}

Edge* EdgeList::getTail(){
    return tail;
}