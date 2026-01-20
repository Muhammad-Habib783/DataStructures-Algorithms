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
    LinkedList();                 // Constructor
    void traverse();              // Display list
    void deleteByValue(int value); // Delete node by value
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
// Delete node by value
void LinkedList::deleteByValue(int value) 
{
    if (!head) 
    {
        cout<<"List is empty!"<<endl;
        return;
    }
// If head needs to be deleted
    if (head->data == value) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted " << value << " from beginning." << endl;
        return;
    }
  Node* current = head;
    while (current->next && current->next->data != value)
        current = current->next;

    if (!current->next) 
    {
        cout << "Value " << value << " not found in list." << endl;
        return;
    }

    Node* toDelete = current->next;
    current->next = current->next->next;
    delete toDelete;
    cout << "Deleted " << value << " from list." << endl;
}
// Main function to test delete by value
int main() 
{
    LinkedList list;

    cout << "Initial list:" << endl;
    list.traverse();  // Output: 10 -> 20 -> 30 -> NULL

    cout << "\nDelete value 20:" << endl;
    list.deleteByValue(20);
    list.traverse();  // Output: 10 -> 30 -> NULL

    cout << "\nDelete value 10 (head):" << endl;
    list.deleteByValue(10);
    list.traverse();  // Output: 30 -> NULL

    cout << "\nDelete value 99 (not in list):" << endl;
    list.deleteByValue(99);
    list.traverse();  // Output: 30 -> NULL

    return 0;
}