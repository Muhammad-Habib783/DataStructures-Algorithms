#include<iostream>
using namespace std;
int push(int*stack,int top,int value)
{
	stack[top]=value;
	return top+1;
}
int pop(int*stack,int top)
{
	if(top==0)
	{
		cout<<"\nStack is empty";
	}
	else
	{
		cout<<"\nPopped "<<stack[top-1];
		stack[top-1]=0;
		top--;
	}
	return top;
}
void showStack(int*stack,int top)
{
	if(top==0)
	{
		cout<<"\nStack is empty";
	}
	else
	{
		cout<<"\nStack: ";
		for(int i=top-1;i>=0;i--)
		{
			cout<<stack[i]<<" ";
		}
	}
}
int enqueue(int*queue,int rear,int value)
{
	queue[rear]=value;
	return rear+1;
}
int dequeue(int*queue,int rear)
{
	if(rear==0)
	{
		cout<<"\nQueue is empty";
	}
	else
	{
		cout<<"\nDequeued "<<queue[0];
		for(int i=1;i<rear;i++){
			queue[i-1]=queue[i];
		}
		rear--;
		queue[rear]=0;
	}
	return rear;
}
void showQueue(int*queue,int rear)
{
	if(rear==0)
	{
		cout<<"\nQueue is empty";
	}
	else
	{
		cout<<"\nQueue: ";
		for(int i=0;i<rear;i++)
		{
			cout<<queue[i]<<" ";
		}
	}
}
int main()
{
	int size=10;
	int*stack=new int[size],top=0;
	int*queue=new int[size],rear=0;
	int choice=0,ch=0,value=0;
	cout<<"\n1. STACK";
	cout<<"\n2. QUEUE";
	cout<<"\n3. EXIT";
	cout<<"\nEnter your choice:";
	cin>>choice;
	if(choice==1)
	{
		do
		{
			cout<<"\n1. PUSH";
			cout<<"\n2. POP";
			cout<<"\n3. DISPLAY";
			cout<<"\n4. EXIT";
			cout<<"\nEnter your choice:";
			cin>>ch;
			if(ch==1)
			{
				cout<<"\nEnter value:";
				cin>>value;
				top=push(stack,top,value);
			}
			else if(ch==2)
			{
				top=pop(stack,top);
			}
			else if(ch==3)
			{
				showStack(stack,top);
			}
		}while(ch!=4);
	}
	else if(choice==2)
	{
		do{
			cout<<"\n1. ENQUEUE";
			cout<<"\n2. DEQUEUE";
			cout<<"\n3. DISPLAY";
			cout<<"\n4. EXIT";
			cout<<"\nEnter your choice:";
			cin>>ch;
			if(ch==1)
			{
				cout<<"\nEnter value:";
				cin>>value;
				rear=enqueue(queue,rear,value);
			}
			else if(ch==2)
			{
				rear=dequeue(queue,rear);
			}
			else if(ch==3)
			{
				showQueue(queue,rear);
			}
		}while(ch!=4);
	}
	else
	{
		cout<<"\nInvalid choice";
	}
	delete[]stack;
	delete[]queue;
	return 0;
}