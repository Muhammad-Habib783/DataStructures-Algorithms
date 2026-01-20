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
    LinkedList();                         // Constructor
    void traverse();                      // Print all nodes
    void insertBefore(int target, int value); // Insert before a node
    void insertAfter(int target, int value);  // Insert after a node
    void deleteByValue(int value);        // Delete a node by value
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
// Insert before a node with target value
void LinkedList::insertBefore(int target, int value) 
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if(!head) return;

    if(head->data == target) 
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next && current->next->data != target)
        current = current->next;

    if(!current->next) 
    {
        cout << "Target value not found!" << endl;
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}
// Insert after a node with target value
void LinkedList::insertAfter(int target, int value) 
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    Node* current = head;
    while(current && current->data != target)
        current = current->next;

    if(!current) 
    {
        cout << "Target value not found!" << endl;
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}
// Delete a node by value
void LinkedList::deleteByValue(int value) 
{
    if (!head) return;

    if (head->data == value) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
   Node* current = head;
    while (current->next && current->next->data != value)
        current = current->next;

    if (!current->next) 
    {
        cout << "Value not found!" << endl;
        return;
    }

    Node* toDelete = current->next;
    current->next = current->next->next;
    delete toDelete;
}
// Main function to test all operations
int main() 
{
    LinkedList list;

    cout << "Initial list:" << endl;
    list.traverse();  // 10 -> 20 -> 30 -> NULL

    cout << "\nInsert 15 before 20:" << endl;
    list.insertBefore(20, 15);
    list.traverse();  // 10 -> 15 -> 20 -> 30 -> NULL

    cout << "\nInsert 25 after 20:" << endl;
    list.insertAfter(20, 25);
    list.traverse();  // 10 -> 15 -> 20 -> 25 -> 30 -> NULL

    cout << "\nDelete node with value 15:" << endl;
    list.deleteByValue(15);
    list.traverse();  // 10 -> 20 -> 25 -> 30 -> NULL

    return 0;
}