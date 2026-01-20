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
    void createLoop();        // Manually create a loop
    bool detectLoop();        // Detect loop
    void removeLoop();        // Remove loop
    void traverse();          // Print list
};
// Constructor: create list
LinkedList::LinkedList() 
{
    head = nullptr;

    Node* a = new Node{10, nullptr};
    Node* b = new Node{20, nullptr};
    Node* c = new Node{30, nullptr};
    Node* d = new Node{40, nullptr};

    head = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = nullptr; // initially no loop
}
// Create a loop manually (for testing)
void LinkedList::createLoop() 
{
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = head->next; // loop: 40 → 20
}
// Detect loop using Floyd’s algorithm
bool LinkedList::detectLoop() 
{
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}
// Remove loop
void LinkedList::removeLoop() 
{
    Node* slow = head;
    Node* fast = head;

    // First detect loop
    bool loopExists = false;
    while (fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) 
        {
            loopExists = true;
            break;
        }
    }
    if (!loopExists) 
    return;
    // Move one pointer to head
    slow = head;
    while (slow != fast) 
    {
        slow = slow->next;
        fast = fast->next;
    }
    // Find the node before loop start
    Node* prev = fast;
    while (prev->next != fast)
        prev = prev->next;
    prev->next = nullptr; // break the loop
}
// Traverse the list
void LinkedList::traverse() 
{
    Node* temp = head;
    int count = 0;
    while (temp && count < 20) 
    { // limit to avoid infinite loop
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
    }
    cout << "NULL" << endl;
}
// Main function
int main() 
{
    LinkedList list;
    cout << "Original list:" << endl;
    list.traverse();
    cout << "\nCreating loop..." << endl;
    list.createLoop();
    if (list.detectLoop())
        cout << "Loop detected!" << endl;
    else
        cout << "No loop detected." << endl;

    cout << "\nRemoving loop..." << endl;
    list.removeLoop();
    if (list.detectLoop())
        cout << "Loop still exists!" << endl;
    else
        cout << "Loop removed successfully." << endl;

    cout << "\nFinal list:" << endl;
    list.traverse();

    return 0;
}