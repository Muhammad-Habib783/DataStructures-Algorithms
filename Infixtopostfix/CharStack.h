#include<iostream>
#include<stdlib.h>
using namespace std;
class CharStack
{
	private:
		char *stackArray;
		int stackSize;
		int top;
	public:
		CharStack(int);			// Constructor
		~CharStack();			// Destructor
		void Push(char);
		void Pop();
		char Top();
		bool isFull();
		bool isEmpty();
		void Display();
};
// Constructor
CharStack :: CharStack(int size)
{
	stackArray = new char[size];
	stackSize = size;
	top = -1;
}	
// Destructor
CharStack :: ~CharStack() 
{ 
	delete [] stackArray;
}
// Push function
void CharStack::Push(char ch)
{
	if (isFull())
	{
		cout << "The stack is full.\n";
	}
	else
	{
		top++;
		stackArray[top] = ch;
	}
}
// Pop function
void CharStack::Pop()
{
	if (isEmpty())
	{
		cout << "The stack is empty.\n";
	}
	else
	{
		top--;
	}
}
// Returns the element at top of the stack
char CharStack::Top()
{
	char ch = stackArray[top];
	return ch;
}
//isFull function
bool CharStack::isFull()
{
	bool status;
	
	if (top == stackSize - 1)
		status = true;
	else
		status = false;
	return status;
}
//isEmpty function
bool CharStack::isEmpty()
{
	bool status;
	
	if (top == -1)
		status = true;
	else
		status = false;
	return status;
}
// Display function
void CharStack::Display()
{
	if(isEmpty())
	{
		cout << "The stack is empty.\n";
	}
	else
	{
		int t = top;
	    while(t >= 0)
	    {
	        cout << "stackArray[" << t << "] = " << stackArray[t] << endl;
	        t--;
	    }	
	}
}
