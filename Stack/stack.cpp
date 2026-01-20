#include <iostream>
using namespace std;
class IntStack
{
	private:
		int *stackArray;
		int stackSize;
		int top;
		
	public:
		IntStack(int);			// Constructor
		~IntStack(void);		// Destructor
		void Push(int);
		int Pop(void);
		bool isFull(void);
		bool isEmpty(void);
		void Display(void);
};
// Constructor
IntStack :: IntStack(int size)
{
	stackArray = new int[size];
	stackSize = size;
	top = -1;
}	
// Destructor
IntStack :: ~IntStack(void) 
{
	delete [] stackArray;
}
// Push function
void IntStack::Push(int num)
{
	if(isFull())
	{
		cout<<"The stack is full.\n";
	}
	else
	{
		top++;
		stackArray[top] = num;
	}
}
// Pop function
int IntStack::Pop()
{
	int data;
	if (isEmpty())
	{
		cout<<"The stack is empty.\n";
	}
	else
	{
	    data = stackArray[top];
		top--;
	}
	return data;
}
//isFull function
bool IntStack::isFull(void)
{
	bool status;
	
	if (top == stackSize - 1)
		status = true;
	else
		status = false;
	return status;
}
//isEmpty function
bool IntStack::isEmpty(void)
{
	bool status;
	
	if (top == -1)
		status = true;
	else
		status = false;
	return status;
}
// Display function
void IntStack::Display()
{
	if(isEmpty())
	{
		cout<<"The stack is empty.\n";
	}
	else
	{
		int t = top;
	    while(t >= 0)
	    {
	        cout << "stackArray[" << t
			 << "] = " << stackArray[t] << endl;
	        t--;
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
	
	//myStack.Push(5);

    myStack.Display();
int x = myStack.Pop(); 
cout<<"\n Popped value: "<<x<<endl;
  
    myStack.Display();

    myStack.isFull();

	 myStack.isEmpty();
 
 
    return 0;
}

