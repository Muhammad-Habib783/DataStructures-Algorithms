#include <iostream>
using namespace std;
class LinkedList 
{
public:
    // Node structure inside the class
    class Node 
    {
    public:
        int data;
        Node* next;
    };
   Node* head;
   LinkedList();                          // Constructor
    void traverse();                       // Display list
    void deleteFromBeginning();            // Delete from beginning
    void deleteFromEnd();                  // Delete from end
    void deleteFromPosition(int position); // Delete from specific position
};
// Constructor definition
LinkedList::LinkedList() 
{
    head = nullptr;

    // Create initial list manually
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
// Delete from beginning
void LinkedList::deleteFromBeginning() 
{
    if(!head) 
    {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}
// Delete from end
void LinkedList::deleteFromEnd() 
{
    if (!head) 
    {
        cout << "List is empty!" << endl;
        return;
    }
    if (!head->next) 
    {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}
// Delete from specific position
void LinkedList::deleteFromPosition(int position) 
{
    if (!head) 
    {
        cout << "List is empty!" << endl;
        return;
    }
    if (position == 0) 
    {
        deleteFromBeginning();
        return;
    }
    Node* temp = head;
    for (int i = 0; temp->next && i < position - 1; i++)
        temp = temp->next;
    if (!temp->next) 
    {
        cout << "Position out of bounds!" << endl;
        return;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}
// Main function to test delete scenarios
int main() 
{
    LinkedList list;

    cout << "Initial list:" << endl;
    list.traverse();  // Output: 10 -> 20 -> 30 -> NULL

    cout << "\nDelete from beginning:" << endl;
    list.deleteFromBeginning();
    list.traverse();  // Output: 20 -> 30 -> NULL

    cout << "\nDelete from end:" << endl;
    list.deleteFromEnd();
    list.traverse();  // Output: 20 -> NULL

    cout << "\nDelete from position 0:" << endl;
    list.deleteFromPosition(0);
    list.traverse();  // Output: NULL

    return 0;
}