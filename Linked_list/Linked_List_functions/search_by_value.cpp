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
    void traverse();          // Display list
    bool search(int value);   // Search by value
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
    while (temp) 
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
// Search for a value
bool LinkedList::search(int value) 
{
    Node* temp = head;
    while(temp) 
    {
        if (temp->data == value)
            return true;
        temp = temp->next;
    }
    return false;
}
// Main function to test search
int main() 
{
    LinkedList list;

    cout << "Current list:" << endl;
    list.traverse();  // Output: 10 -> 20 -> 30 -> NULL

    int value;
    cout << "\nEnter value to search: ";
    cin >> value;

    if (list.search(value))
        cout << "Value " << value << " found in the list." << endl;
    else
        cout << "Value " << value << " not found in the list." << endl;

    return 0;
}