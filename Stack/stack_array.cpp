#include <iostream>
using namespace std;
class IntStack 
{
private:
    int* stackArray;
    int stackSize;
    int top;
public:
    IntStack(int);
    ~IntStack();
    void Push(int);
    int Pop();
    bool isFull();
    bool isEmpty();
    void Display();
};
IntStack::IntStack(int size) 
{
    stackArray = new int[size];
    stackSize = size;
    top = -1;
}
IntStack::~IntStack() 
{
    delete[] stackArray;
}
void IntStack::Push(int num) 
{
    if (isFull()) 
    {
        cout << "The stack is full.\n";
    }
    else 
    {
        top++;
        stackArray[top] = num;
    }
}
int IntStack::Pop() 
{
    int data;
    if(isEmpty()) 
    {
        cout << "The stack is empty.\n";
    }
    else
    {
        data = stackArray[top];
        top--;
    }
    return data;
}
bool IntStack::isFull()
{
    return top == stackSize - 1;
}
bool IntStack::isEmpty() 
{
    return top == -1;
}
void IntStack::Display() 
{
    if(isEmpty()) 
    {
        cout << "The stack is empty.\n";
    } 
    else 
    {
        for (int i = top; i >= 0; i--) {
            cout << "stackArray[" << i << "] = " << stackArray[i] << endl;
        }
    }
}
int main() 
{
    IntStack myStack(11);

    myStack.Push(5);
    myStack.Push(10);
    myStack.Push(15);
    myStack.Push(5);
    myStack.Push(55);
    myStack.Push(5);
    myStack.Push(3);
    myStack.Push(7);
    myStack.Push(6);
    myStack.Push(3);
    myStack.Push(5);

    myStack.Display();

    myStack.Pop();
    myStack.Display();

    myStack.isFull();

    return 0;
}