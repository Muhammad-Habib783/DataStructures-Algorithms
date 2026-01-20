#include<iostream>
#include<stdlib.h>
#include"IntLinkedList.h"
using namespace std;
//========================================== main function ====================================
int main()
{
	
	int option,num ;
	
	IntLinkedList *myLinkedList = new IntLinkedList() ;
	
	Menu :
		cout<<"\n-----------------------------------------------------------\n" 
		 << "               Linked List Operations"
		 << "\n===========================================================\n"
		 << "1.  Append                        8.  Destroy\n" 
		 << "2.  Insert                        9.  Delete Less Than\n" 
		 << "3.  Delete Value                  10. Delete Greater Than\n"
		 << "4.  Display                       11. List Size\n" 	
		 << "5.  Sort                          12. Exit\n"
		 << "6.  Search                        13. Menu\n" 
		 << "7.  Reverse                       14. Clear Screen           \n"
		 << "-----------------------------------------------------------\n" ;
	do
	{	 
		cout << "\nEnter Your Option: " ;
		cin >> option ;
		
		switch(option)
		{
			// Appending A node
			case 1 :
				cout << "Enter a number to Append in the List : " ;
				cin >> num ;
				myLinkedList->AppendNode(num) ;
				break ;
				
			// Inserting A node
			case 2 :
				cout << "Enter a Number to Insert in the List : " ;
				cin >> num ;
				myLinkedList->InsertNode(num) ;
				break ;	
			
			// Deleting a Node
			case 3 :
				if(myLinkedList->head == NULL)
					cout << "The List is empty.\n" ;
				else
				{
					myLinkedList->DisplayList() ;
					cout << "Enter the value to be Deleted: " ;
					cin >> num ;
					myLinkedList->DeleteNode(num) ;
				}
				break ;
			
			// Displaying a Node	
			case 4 :
				if(myLinkedList->head == NULL)
					cout << "The List is empty.\n" ;
					
				else
					myLinkedList->DisplayList() ;
				break ;
				
				
			// Displaying a Node	
			case 5 :
				if(myLinkedList->head == NULL)
					cout<< "The List is empty.\n" ;
					
				else
					myLinkedList->SortList() ;
				break ;	
			
			// Searching A node
			case 6 :
				if(myLinkedList->head == NULL)
					cout<< "The List is empty.\n" ;
					
				else
				{
					cout << "Enter the value to be Searched: " ;
					cin >> num ;
					myLinkedList->SearchList(num) ;
				}
				break ;
			
			
			// Reversing
			case 7 :
				if(myLinkedList->head == NULL)
					cout << "The List is empty.\n" ;
					
				else
					myLinkedList->ReverseList() ;
					
				break ;
				
			// Destructor	
			case 8 :
				if(myLinkedList->head == NULL)
					cout << "The List is empty.\n" ;
					
				else
					myLinkedList->~IntLinkedList() ;
					
				break ;
				
				
			// Delete Less than
			case 9 :
				if(myLinkedList->head == NULL)
					cout<< "The List is empty.\n" ;
					
				else
				{
					cout<< "Enter a number to delete all numbers less than the given number : " ;
					cin >> num ;
					myLinkedList->DeleteLess(num);
				}
				break ;
				
				
			// Delete Greater than
			case 10 :
				if(myLinkedList->head == NULL)
					cout << "The List is empty.\n" ;
					
				else
				{
					cout << "Enter a number to delete all numbers greater than the given number : " ;
					cin >> num ;
					myLinkedList->DeleteGreater(num) ;
				}
				break ;
			
			
			case 11 :
				if(myLinkedList->head == NULL)
					cout << "The List is empty.\n" ;		
				else
					myLinkedList->ListSize() ;
					
				break ;	
			
			// Exit
			case 12 :
				exit(0) ;
				
			case 13 :
				goto Menu ;
				break ;
				
			case 14 :
				system("cls") ;
				goto Menu ;
				break ;
				
			default :
				cout << "Invalid Option.\n" ;
				break ;
		}
		
		
	}while(true) ;
    return 0 ;
}



