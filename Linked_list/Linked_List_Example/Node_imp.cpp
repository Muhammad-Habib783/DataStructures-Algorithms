#include"Node.h"
#include<iostream>
using namespace std;
// constructors
Node::Node()
{
    data=0;
    next=NULL;
}
Node::Node(int data)
{
    this->data=data;
    next=NULL;
}
// getters and setters 
void Node::setData(int data)
{
    this->data=data;
}
int Node::getData()
{
    return data;
}
void Node::setNext(Node* next)
{
    this->next=next;
}
Node* Node::getNext()
{
    return next;
}