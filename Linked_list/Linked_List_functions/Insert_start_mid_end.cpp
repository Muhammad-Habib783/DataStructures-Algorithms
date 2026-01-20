#include <iostream>
using namespace std;
class LinkedList 
{
public:
    // Node structure without constructor
    class Node 
    {
    public:
        int data;
        Node* next;
    };

    Node* head;

    LinkedList();                          // Constructor
    void insertAtBeginning(int value);     // Insert at beginning
    void insertAtEnd(int value);           // Insert at end
    void insertAtPosition(int value, int position); // Insert at specific position
    void traverse();                       // Display list
};
// Constructor definition
LinkedList::LinkedList() 
{
    head = nullptr;
}
// Insert at beginning
void LinkedList::insertAtBeginning(int value) 
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
// Insert at end
void LinkedList::insertAtEnd(int value) 
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if(!head) 
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next)
        temp = temp->next;
    temp->next = newNode;
}
// Insert at specific position
void LinkedList::insertAtPosition(int value, int position) 
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if(position == 0) 
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for(int i = 0; temp && i < position - 1; i++)
        temp = temp->next;

    if(!temp) 
    {
        cout << "Position out of bounds!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
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
// Main function to test all insert scenarios
int main() 
{
    LinkedList list;

    cout << "Insert at end:" << endl;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.traverse();  // Output: 10 -> 20 -> NULL

    cout << "\nInsert at beginning:" << endl;
    list.insertAtBeginning(5);
    list.traverse();  // Output: 5 -> 10 -> 20 -> NULL

    cout << "\nInsert at position 2:" << endl;
    list.insertAtPosition(15, 2);
    list.traverse();  // Output: 5 -> 10 -> 15 -> 20 -> NULL

    return 0;
}