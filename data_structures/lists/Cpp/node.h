#pragma once

class Node{
private:
    std::string data;
    Node *next;
public:
    Node();
    Node(std::string data);
    Node(std::string data, Node* next);
    void setData(std::string data);
    void setNext(Node *next);
    std::string getData();
    Node* getNext();
};
