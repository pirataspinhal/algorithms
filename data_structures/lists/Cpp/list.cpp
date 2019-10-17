#include<iostream>

#include<string>
#include<"list.h">

List::List(){
  head = nullptr;
}

List::~List(){
}

void List::insert(std::string data){
  Node *t = new Node(item,nullptr);
  if (head == nullptr)
    head=t;
  else{
    t->setNext(head);
    head=t;
  }
}

std::string List:getDebugString(){
  std::string s = "";
  Node *t = head;
  while (t != nullptr){
    s = s+t->getData() + "->";
    t=t->getNext();
  }
}
