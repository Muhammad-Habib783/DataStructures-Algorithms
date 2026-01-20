#include<iostream>
#include<stdlib.h>
using namespace std;
class IntLinkedList
{
	private:
		struct ListNode	 // Structure for linked list
		{
			int value;
			struct ListNode *next;
		};
				// size of the list
	public:
		
	ListNode *head;	// List head  pointer
		int size;
		
		IntLinkedList(void)		// Constructor
		{ 
			head = NULL; 
			size = 0;
		}
		
		~IntLinkedList(void);	// Destructor - Destroy function
		
		void AppendNode(int);
		void InsertNode(int);
		void DeleteNode(int);
		void DisplayList(void);
		void SortList(void);
		void SearchList(int);
		void ReverseList(void);
		void ListSize(void);
		
		void DeleteLess(int);		
		void DeleteGreater(int);
		
		int isEmpty();
};
// ----------------------- Append node ------------------------------
void IntLinkedList :: AppendNode(int num)
{
	ListNode *newNode, *nodePtr;
	newNode = new ListNode;			// Allocate a new node	
	newNode->value = num;					// Store num
	newNode->next = NULL;					// Make the next pointer NULL
	size++;									// Increment the size
	
	if(!head)								// newNode as first node
	head = newNode;
	else									// Otherwise, insert newNode at end
	{
		nodePtr = head;						// Initialize nodePtr to head
		while(nodePtr->next)				// Find the last node in the list
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;			// Insert newNode as the last node
	}
}
// ----------------------- Insert node ------------------------------
void IntLinkedList :: InsertNode(int num)
{
	ListNode *newNode, *nodePtr, *preNode;
	
	newNode = new ListNode;			// Allocate a new node
	newNode->value = num;					// Store num
	size++;									// Increment the size
	
	nodePtr = head;							// Initialize nodePtr to the head of the list
	
	if(!head)
	{
		head = newNode;						// newNode as first node
		newNode->next = NULL;				// point newNode->next to NULL
	}
	else if( num < nodePtr->value )			// if first node is less than num then insert newNode as first node
	{
		nodePtr = head;
        head = newNode;
        head->next = nodePtr;
	}
	else									// Otherwise, insert newNode somewhere in the middle
	{
		// skip all values whose value is less than num			
		while( nodePtr!= NULL && nodePtr->value < num )
		{
			preNode	= nodePtr;
			nodePtr = nodePtr->next;
		}
		if ( preNode == NULL )
		{
			head = newNode;					// newNode as first node
			newNode->next = NULL;			// next of newNode as NULL
		}
		else
		{
			preNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}
// ----------------------- Delete node ------------------------------
void IntLinkedList::DeleteNode(int num)
{
	ListNode *nodePtr, *preNode;	// If the list is empty, do nothing.

	if(head->value == num)				// Determine if the first node is the one
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
		size--;			// decrement the size
	}
	else
	{
		nodePtr = head;	// Initialize nodePtr to head of list
             	
		while (nodePtr != NULL && nodePtr->value != num)  // Skip all nodes whose value member is not equal to num
		{
			preNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// Link the previous node to the node after nodePtr, then delete nodePtr
		preNode->next = nodePtr->next;
		delete nodePtr;
		
		size--;		// decrement the size
	}
}
// ----------------------- Display Linked List ------------------------------
void IntLinkedList :: DisplayList(void)
{
	ListNode *nodePtr;
	nodePtr = head;	 // Initialize nodePtr to head of list

	cout << "Integer Linked List = ";
	
	while (nodePtr)
	{
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}		
	cout<< endl;
}
// ----------------------- Destory List ------------------------------
void IntLinkedList :: ListSize(void)
{
	ListNode *nodePtr;
	
	int Size = 0;
	
	if(!head)
	{
		cout << "\nList is empty.\n" ;
		return ;
	}
	
	nodePtr = head ;
	
	while(nodePtr)
	{
		Size++ ;
		nodePtr = nodePtr->next ; 
	}
	
	cout << "The size of the List is : " << Size << endl ;
}
// ----------------------- Destory List ------------------------------
IntLinkedList :: ~IntLinkedList ( void )
{
	ListNode *nodePtr, *nextNode;
	
	nodePtr = head;	 // Initialize nodePtr to head of list
	while ( nodePtr != NULL )
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
	size = 0;
}
// ----------------------- Search List ------------------------------
void IntLinkedList :: SearchList(int num)
{
	int value, pos = 0;
    bool flag = false;
       
    ListNode *temp;
    temp = head;
    while (temp != NULL)
    {
        pos++;
        if (temp->value == num)
        {
            flag = true;
            cout<<"Element "<< num <<" is found at position "<<pos<<endl;
        }
        temp = temp->next;
    }
    if (!flag)
        cout<<"Element "<< num <<" not found in the list!"<<endl;  
}
// ----------------------- Sort List ------------------------------
void IntLinkedList :: SortList()
{
    ListNode *nodePtr, *temp;
    int value;
    
    if ( isEmpty() )
    {
        cout<<"The list is empty!"<<endl;
        return;
    }
    else
	{
		nodePtr = head;
	    
		// while nodePtr is NOT NULL
		while (nodePtr)
	    {
	        // loop throught the list
			for ( temp = nodePtr->next; temp != NULL; temp = temp->next )
	        {
	            
				// compare if previous value is greater than next value
				if ( nodePtr->value > temp->value )
	            {
	                // swap the values
					value = nodePtr->value;
	                nodePtr->value = temp->value;
	                temp->value = value;
	            }
	        }
	        // move the pointer to the next node
			nodePtr = nodePtr->next;
	    }	
	}
}
// ----------------------- Status Check for Empty List ------------------------------
int IntLinkedList :: isEmpty()
{
	if (size == 0)
		return 1;
	else
		return 0;
}
// ----------------------- Reverse List ------------------------------
void IntLinkedList :: ReverseList()
{
    ListNode *previous, *current, *next;	// declare three pointers
    
    previous    = NULL;				// point all pointer to Null
    current 	= NULL;
    next    	= NULL;
    
	current = head;					// point current to the head of list
    
	while(current != NULL)			// traverse the list using current pointer
	{
        next = current->next;		// save pointer to next node of current to the next pointer
        current->next = previous;	// save previous node to the next pointer of current
        previous = current;			// save current node as previous node
        current = next;				// make next node, the current node
    }
    head = previous;			    // now let the head point at the last node (pre)
}
// ----------------------- Delete Less Than ------------------------------
void IntLinkedList :: DeleteLess(int num)
{
	ListNode *nodePtr , *preNode , *nextNode , *checkPtr;
	
	if(head == NULL)
		cout << "The List is empty.\n" ;	
	else
	{
		int count = 0 ;
	
		if(!head)
		{
			cout << "\nList is empty.\n" ;
			return ;
		}
	
		checkPtr = head ;
		while(checkPtr)
		{
			if(num == checkPtr->value)
				count++ ;
			
			checkPtr = checkPtr->next ; 
		}
	
		if(count == 0)
		{
			cout<< "\nValue is not in the list.\n" ;
		}	
		
		else
		{
			
			if(head->value < num)
			{
				ListNode *temp ;
				while(head != NULL && head->value < num)
				{
					temp = head->next ;
					delete head ;
					head = temp ;
				}
			}
			
			if(head != NULL)
			{
				nodePtr = head ;
				preNode = nodePtr ;
				nodePtr = nodePtr->next ;
				
				while(nodePtr)
				{
					if(nodePtr->value < num)
					{
						nextNode = nodePtr->next ;
						delete nodePtr ;
						nodePtr = nextNode ;
						preNode->next = nextNode ;
					}
					else
					{
						preNode = nodePtr ;
						nodePtr = nodePtr->next ;
					}
				}
			}	
				cout << "All numbers less than " << num << " have been deleted.\n" ;
			}
		}		
	}
// ----------------------- 	Delete Greater Than ------------------------------	
void IntLinkedList :: DeleteGreater(int num)
{
	ListNode *nodePtr , *preNode , *nextNode , *checkPtr ;
		
		if(head == NULL)
			cout << "The List is empty.\n" ;	
		else
		{
			int count = 0 ;
		
			if(!head)
			{
				cout << "\nList is empty.\n" ;
				return ;
			}
		
			checkPtr = head ;
			while(checkPtr)
			{
				if(num == checkPtr->value)
					count++ ;
				
				checkPtr = checkPtr->next ; 
			}
		
			if(count == 0)
			{
				cout << "\nValue is not in the list.\n" ;
			}	
			
			else
			{
				
				if(head->value > num)
				{
					ListNode *temp ;
					while(head != NULL && head->value > num)
					{
						temp = head->next ;
						delete head ;
						head = temp ;
					}
				}
				
				if(head != NULL)
				{
					nodePtr = head ;
					preNode = nodePtr ;
					nodePtr = nodePtr->next ;
					
					while(nodePtr)
					{
						if(nodePtr->value > num)
						{
							nextNode = nodePtr->next ;
							delete nodePtr ;
							nodePtr = nextNode ;
							preNode->next = nextNode ;
						}
						else
						{
							preNode = nodePtr ;
							nodePtr = nodePtr->next ;
						}
					}
				}
					
					
					cout << "All numbers greater than " << num << " have been deleted.\n" ;
				}
			}		
		}
