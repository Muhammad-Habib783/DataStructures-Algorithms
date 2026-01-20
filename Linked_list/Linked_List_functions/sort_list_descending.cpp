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
    void sortDescending(); // Sort the list in descending order
};
// Constructor: create initial list
LinkedList::LinkedList() 
{
    head = nullptr;

    Node* first = new Node;
    first->data = 30;
    first->next = nullptr;
    head = first;

    Node* second = new Node;
    second->data = 10;
    second->next = nullptr;
    first->next = second;

    Node* third = new Node;
    third->data = 20;
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
// Sort the list in descending order (Bubble Sort)
void LinkedList::sortDescending() 
{
    if (!head || !head->next)
        return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next) 
        {
            if (current->data < current->next->data) 
            {
                // Swap data
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}
// Main function to test descending sort
int main() 
{
    LinkedList list;

    cout << "Original list:" << endl;
    list.traverse();  // Output: 30 -> 10 -> 20 -> NULL

    cout << "\nSorted list (descending):" << endl;
    list.sortDescending();
    list.traverse();  // Output: 30 -> 20 -> 10 -> NULL

    return 0;
}