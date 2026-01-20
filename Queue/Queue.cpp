#include<iostream>
#include<stdlib.h>
using namespace std;
//--------------------------- Class for the queue ---------------------
class IntQueue
{
	private:
		int *queueArray;
		int queueSize;
		int rear, front;
	public:
		IntQueue(int);			// Constructor
		void Enqueue(int);
		int  Dequeue(void);
		bool isFull(void);
		bool isEmpty(void);
		void Display(void);
};
//=====================================================main function=========================
int main()
{
    int size = 10;  
    IntQueue myQueue = IntQueue(size);
    int option;
    main:
		system("cls");     
        cout <<"\n-----------------------------------------------------------\n" 
		     <<"                 Queue Operations"
		     <<"\n===========================================================\n";
        
        cout <<" 1. Enqueue an element. " << endl ;
        cout <<" 2. Dequeue an element. " << endl ;
        cout <<" 3. Display Queue elements. " << endl ;
        cout <<" 0. Exit program." << endl;
        cout << endl << "\nEnter Your Option: ";
        cin  >> option ;
        switch(option)
        {
            case 1:
                int value;
                cout << " Enter number to Enqueue: " ;
                cin  >> value;

                myQueue.Enqueue(value);
                cout << " Number enqueued!" << endl ;
                goto main;
                
            case 2:
                if(!myQueue.isEmpty())
                {
                    cout << " Number is: " << myQueue.Dequeue() << endl ;
                }
                else
                    cout << " Queue is empty!" << endl ;

                goto main;
                
             case 3:
                if(!myQueue.isEmpty())
                {
                	myQueue.Display();
                }
                else
                    cout << " Queue is empty!" << endl ;

                goto main;     
                
            case 0:
                break;
                
            default:
                goto main;
        }

}
//--------------------------- Constructor initializes the queue ---------------------
IntQueue :: IntQueue(int size)
{
	queueArray = new int[size];
	queueSize  = size;
	rear  = -1;
	front = -1;
}
//--------------------------- Add (Enqueue) an element to the queue -----------------
void IntQueue::Enqueue(int num)
{
	if ( isFull() )
	{
		cout << "The queue is full.\n";
	}
	else
	{
		rear++;
		queueArray[rear] = num;
	}
}
//--------------------------- Remove (Dequeue) an element from the queue -----------------
int IntQueue :: Dequeue(void)
{
	int data;
	
	if (isEmpty())
		cout << "The queue is empty.\n";
	else
	{
		front++;
		data = queueArray[front];	
	}
	return data;
}
//--------------------------- Check Queue Full Status -----------------
bool IntQueue :: isFull(void)
{
	bool status;
	
	if( rear == queueSize - 1 )	
	  status = true;
	else	
	  status = false;

	return status;
  }
//--------------------------- Check Queue Empty Status -----------------
bool IntQueue :: isEmpty(void)
{
	bool status;
	
	if(front == rear)
	  status = true;
	else
	  status = false;

	return status;
}
//--------------------------- Display Queue Elements -----------------
void IntQueue :: Display(void)
{
	char temp;
	
	if (isEmpty())
	{
		cout << "The Queue is empty.\n";
	}
	else
	{
	for(int i = front + 1; i <= rear; i++)
	  cout <<"queueArray[" << i << "] = " << queueArray[i] << endl;
	}
	cout <<"\n Press any key to continue ... \n" ;
	cin >>temp;
}