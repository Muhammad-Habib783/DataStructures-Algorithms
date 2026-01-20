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

    LinkedList();         // Constructor
    void traverse();      // Print all nodes
    void reverse();       // Reverse the list
};
// Constructor: create initial list
LinkedList::LinkedList() 
{
    head = nullptr;

    Node* first = new Node;
    first->data = 10;
    first->next = nullptr;
    head = first;

    Node* second = new Node;
    second->data = 20;
    second->next = nullptr;
    first->next = second;

    Node* third = new Node;
    third->data = 30;
    third->next = nullptr;
    second->next = third;
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
// Reverse the list
void LinkedList::reverse() 
{
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}
// Main function to test traverse and reverse
int main() 
{
    LinkedList list;

    cout << "Original list:" << endl;
    list.traverse();  // Output: 10 -> 20 -> 30 -> NULL

    cout << "\nReversed list:" << endl;
    list.reverse();
    list.traverse();  // Output: 30 -> 20 -> 10 -> NULL

    return 0;
}