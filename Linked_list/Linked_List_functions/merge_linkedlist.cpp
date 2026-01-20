#include <iostream>
using namespace std;
class LinkedList 
{
public:
    class Node 
    {
    public:
        int data;
        Node* next;
    };

    Node* head;

    LinkedList();             // Constructor
    void traverse();          // Print all nodes
    void merge(LinkedList& other); // Merge another list
};
// Constructor: create empty list
LinkedList::LinkedList() 
{
    head = nullptr;
}
// Traverse the list
void LinkedList::traverse() 
{
    Node* temp = head;
    while(temp) 
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
// Merge another list into this one
void LinkedList::merge(LinkedList& other) 
{
    if(!head)
     {
        head = other.head;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = other.head;
}
// Main function to test merging
int main() 
{
    LinkedList list1;
    LinkedList list2;

    // Manually create list1: 10 -> 20 -> NULL
    LinkedList::Node* a = new LinkedList::Node;
    a->data = 10;
    a->next = nullptr;
    list1.head = a;

    LinkedList::Node* b = new LinkedList::Node;
    b->data = 20;
    b->next = nullptr;
    a->next = b;

    // Manually create list2: 30 -> 40 -> NULL
    LinkedList::Node* x = new LinkedList::Node;
    x->data = 30;
    x->next = nullptr;
    list2.head = x;

    LinkedList::Node* y = new LinkedList::Node;
    y->data = 40;
    y->next = nullptr;
    x->next = y;

    cout << "List 1:" << endl;
    list1.traverse();

    cout << "\nList 2:" << endl;
    list2.traverse();

    // Merge list2 into list1
    list1.merge(list2);

    cout << "\nMerged List:" << endl;
    list1.traverse();  // Output: 10 -> 20 -> 30 -> 40 -> NULL
    return 0;
}