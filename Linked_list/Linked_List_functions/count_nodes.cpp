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
    int countNodes();     // Count total nodes
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
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
// Count total nodes
int LinkedList::countNodes() 
{
    int count = 0;
    Node* temp = head;
    while(temp) 
    {
        count++;
        temp = temp->next;
    }
    return count;
}
// Main function to test node counting
int main() 
{
    LinkedList list;

    cout << "Current list:" << endl;
    list.traverse();  // Output: 10 -> 20 -> 30 -> NULL

    int total = list.countNodes();
    cout << "\nTotal number of nodes: " << total << endl;  // Output: 3

    return 0;
}