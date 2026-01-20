#include <iostream>
using namespace std;
// Node class definition
class Node 
{
private:
    int data;
    Node* next;

public:
    Node() 
    {
        data = 0;
        next = NULL;
    }

    Node(int data) 
    {
        this->data = data;
        next = NULL;
    }

    int getData() 
    {
        return data;
    }

    void setData(int data) 
    {
        this->data = data;
    }

    Node* getNext() 
    {
        return next;
    }

    void setNext(Node* next) 
    {
        this->next = next;
    }
};
// List class definition
class List 
{
private:
    Node* head;
    Node* tail;

public:
    List() 
    {
        head = NULL;
        tail = NULL;
    }

    void setHead(Node* head) 
    {
        this->head = head;
    }

    Node* getHead() 
    {
        return head;
    }

    void setTail(Node* tail) 
    {
        this->tail = tail;
    }

    Node* getTail() 
    {
        return tail;
    }

    bool isEmpty() 
    {
        return head == NULL;
    }
   Node* findNode(int toFind) 
    {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->getData() == toFind) 
            {

                return temp;
            }
            temp = temp->getNext();
        }
        return NULL;
    }
   void insertAtHead(int data) 
   {
        Node* temp = new Node(data);
        if (isEmpty()) 
        {
            head = temp;
            tail = temp;
        } 
        else 
        {
            temp->setNext(head);
            head = temp;
        }
    }
   void insertAtTail(int data) 
   {
        if (isEmpty()) 
        {
            insertAtHead(data);
        } 
        else 
        {
            Node* temp = new Node(data);
            tail->setNext(temp);
            tail = temp;
        }
    }
   void insertAtTarget(int target, int data) 
   {
        Node* temp = findNode(target);
        if (temp == NULL) 
        {
            cout << "Target not found" << endl;
            return;
        }
    if(temp == tail) 
    {
            insertAtTail(data);
        } 
        else if(temp == head)
        {
            insertAtHead(data);
        } 
        else 
        {
            Node* newNode = new Node(data);
            newNode->setNext(temp->getNext());
            temp->setNext(newNode);
        }
    }
     void print() 
     {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->getData() << endl;
            temp = temp->getNext();
        }
    }
};
// Main function
int main() 
{
    List l1;
    l1.insertAtHead(5);
    l1.insertAtHead(10);
    l1.insertAtTail(15);
    l1.insertAtTail(45);
    l1.insertAtTarget(12, 15); // 12 not in list, should show "Target not found"
    l1.print();
    return 0;
}