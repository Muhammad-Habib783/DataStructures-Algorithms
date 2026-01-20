#include<iostream>
using namespace std;
struct Node
{
 int data;
  Node *link;
};
int main()
{
    Node *head = new Node();
    head->data=46;
    cout<<"\n "<<head->data;
    head->link=nullptr;
    return 0;
}