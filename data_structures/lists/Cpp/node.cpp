#include <iostream>
#include "node.h"
Node::Node() : next(nullptr)
{
}

Node::Node(std::string data){
    this->data = data;
    this->next = nullptr;
}

Node::Node(std::string data, Node *next){
    this->data = data;
    this->next = next;
}

void Node::setData(std::string data){
    this->data = data;
}

void Node::setNext(Node *next){
    this->next = next;
}

std::string Node::getData(){
    return data;
}

Node* Node::getNext(){
    return next;
}
