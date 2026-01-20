#include<iostream>
using namespace std;
// this is class to implement queue of characters
class charQueue 
{
private:
    char*queueArray;     // for dynamic array
    int queueSize;       // for size of queue
    int front;           // for front index
    int rear;            // for rear index
    int count;           // to track number of elements

public:
    charQueue(int);      // Constructor
    ~charQueue();        // Destructor
    void Enqueue(char);  // this can add character to queue
    char Dequeue();      // this function removes character from queue
    bool isFull();       // for check queue is full
    bool isEmpty();      // for check queue is empty
    void Display();      // for display all elements of queue
};
charQueue::charQueue(int size) 
{
    queueSize=size;
    queueArray=new char[size];
    front=0;
    rear=-1;
    count=0;
}
charQueue::~charQueue()
{
    delete[]queueArray;
}
void charQueue::Enqueue(char ch)
 {
    if(isFull()) 
    {
        cout<<"\n Queue is full ";
    } 
    else
     {
        rear=(rear+1)%queueSize; // circular increment
        queueArray[rear]=ch;
        count++;
    }
}
char charQueue::Dequeue() 
{
    if(isEmpty()) 
    {
        cout<<"\n Queue is empty ";
        return '\0';
    } 
    else 
    {
        char ch=queueArray[front];
        front=(front+1)%queueSize;
        count--;
        return ch;
    }
}
// Check if queue is full
bool charQueue::isFull() 
{
    return count==queueSize;
}
// Check if queue is empty
bool charQueue::isEmpty() 
{
    return count==0;
}
// Display queue contents
void charQueue::Display() 
{
    if(isEmpty()) 
    {
        cout<<"\n Queue is empty";
    } 
    else
 {
        int i=front;
        for(int j=0;j<count;j++)
         {
            cout<<"queueArray["<<i<<"]="<<queueArray[i]<<endl;
            i=(i+1)%queueSize;
        }
    }
}
// main function
int main()
 {
    int size=5;
    charQueue myCharQueue(size); // here creating queue of size 5

    cout<<"\n Enqueuing characters \n  ";
    for(int i=0;i<size;i++) 
    {
        myCharQueue.Enqueue('A'+i); // here we add characters
    }

    myCharQueue.Display(); // display queue elements

    cout<<"\n  Dequeuing characters \n  ";
    for(int i=0;i<size;i++)
     {
        cout<<"Dequeued:"<<myCharQueue.Dequeue()<<endl; // remove characters
    }
   return 0;
}