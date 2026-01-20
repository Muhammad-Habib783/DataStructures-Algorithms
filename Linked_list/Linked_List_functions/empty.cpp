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
   bool isEmpty();       // Check if list is empty
};
// Constructor: leave list empty
LinkedList::LinkedList() 
{
    head = nullptr;
}
// Traverse the list
void LinkedList::traverse() 
{
    if(isEmpty()) 
    {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    while(temp) 
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
// Check if list is empty
bool LinkedList::isEmpty() 
{
    return head == nullptr;
}
// Main function to test empty check
int main() 
{
    LinkedList list;

    cout << "Checking if list is empty:" << endl;
    if (list.isEmpty())
        cout << "Yes, the list is empty." << endl;
    else
        cout << "No, the list is not empty." << endl;

    // Add a node manually
    LinkedList::Node* first = new LinkedList::Node;
    first->data = 10;
    first->next = nullptr;
    list.head = first;

    cout << "\nAfter adding a node:" << endl;
    if (list.isEmpty())
        cout << "Yes, the list is empty." << endl;
    else
        cout << "No, the list is not empty." << endl;

    list.traverse();  // Output: 10 -> NULL

    return 0;
}