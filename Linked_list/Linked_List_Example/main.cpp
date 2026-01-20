#include<iostream>
#include"List.h"
using namespace std;
int main()
{
    List l1;
    l1.insertAtHead(5);
    l1.insertAtHead(10);
    l1.insertAtTail(15);
    l1.insertAtTail(45);
    l1.insertAtTarget(12,15);
    l1.print();
    system("pause");
    return 0;
}