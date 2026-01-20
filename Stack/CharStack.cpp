#include<iostream>
using namespace std;
// this is class to implememt stack of characters
class charStack
 {
private:
    char*stackArray;     // for dynamic array
    int stackSize;       // for size of stack
    int top;             // for index
public:
    charStack(int);      // Constructor 
    ~charStack();        // Destructor
    void Push(char);     // this can push character in stack 
    char Pop();          // this function pop character from stack
    bool isFull();       // for check stack is full
    bool isEmpty();      // for check stack is empty
    void Display();      // for display all elements of stack
};
charStack::charStack(int size) 
{
    stackSize=size;
    stackArray=new char[size];
    top=-1;
}
charStack::~charStack() 
{
    delete[]stackArray;
}
void charStack::Push(char ch) 
{
    if(isFull()) // check stack is full or not
    {
        cout<<"\n Stack is full ";
    }
     else 
    {
        top++;
        stackArray[top]=ch; // assign characters to stack by increment
    }
}
char charStack::Pop() 
{
    if(isEmpty()) // check stack is empty or not
    {
        cout<<"\n Stack is empty ";
        return '\0'; // Return null character if stack is empty 
    } 
    else
  {
        char ch=stackArray[top]; // get the characters and then decrement
        top--; 
        return ch;
    }
}
bool charStack::isFull() // check stack is full or not
{
    return top==stackSize-1;
}
bool charStack::isEmpty() // check stack is empty or not
{
    return top==-1;
}
void charStack::Display() 
{
    if(isEmpty()) 
    {
        cout<<"\n Stack is empty";
    } 
    else 
    {
        for(int i=top;i>=0;i--) 
        {
            cout<<"stackArray["<<i<<"]="<<stackArray[i]<<endl; // display stack with index 
        }
    }
}
// main function
int main()
 {
    int size=5;
    charStack myCharStack(size); // here creating stack of size 5

    cout<<"\n Pushing characters \n  ";
    for(int i=0;i<size;i++) 
    {
        myCharStack.Push('A'+i); // here we push characters 
    }
   
    myCharStack.Display(); // display stack elements
   
    cout<<"\n  Popping characters \n  ";
    for(int i=0;i<size;i++)
     {
        cout<<"Popped:"<<myCharStack.Pop()<<endl; // pop characters
    }
   return 0;
}