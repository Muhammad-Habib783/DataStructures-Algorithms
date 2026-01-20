#include"List.h"
#include<iostream>
using namespace std;
// constructors
List::List()
{
    head=NULL;
    tail=NULL;
}
// getters and setters 
void List::setHead(Node* head)
{
    this->head=head;
}
Node* List::getHead()
{
    return head;
}
void List::setTail(Node* tail)
{
    this->tail=tail;
}
Node* List::getTail()
{
    return tail;
}
bool List::isEmpty()
{
    if(head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void List::insertAtHead(int data)
{
    if(isEmpty())
    {
        Node* temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else
    {
        Node* temp=new Node(data);
        temp->setNext(head);
        head=temp;
    }
}
void List::insertAtTail(int data)
{
    if(isEmpty())
    {
        insertAtHead(data);
    }
    else
    {
        Node* temp=new Node(data);
        tail->setNext(temp);
        tail=temp;
    }
}
Node* List::findNode(int toFind)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->getData() == toFind)
        {
            return temp;
        }
        else
        {
        temp=temp->getNext();
        }
    } // end of while loop
    return NULL;
} // end of findNode
void List::insertAtTarget(int target,int data)
{
    Node *temp=findNode(target);
    if(temp == NULL)
    {
        cout<<" not found";
        return;
    }
    else
    {
     if(temp == tail)
     {
         insertAtTail(data);
     }
     else if(temp==head)
     {
         insertAtHead(data);
     }
     else
     {
         Node* newNode=new Node(data);
         newNode->setNext(temp->getNext());
         temp->setNext(newNode);
     }
    }
}// end of insertAtTarget
void List::print()
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->getData()<<endl;
        temp=temp->getNext();
    }
}
    