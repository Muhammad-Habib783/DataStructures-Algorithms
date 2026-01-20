// Binary Search Tree - Implemenation in C++
#include<iostream>
#include<stdlib.h>
using namespace std;
struct BSTNode 						// Definition of Node for Binary search tree
{
	int data; 
	BSTNode* left;
	BSTNode* right;
};
//-------------------------------------------------------------------------------------------
BSTNode* GetNewNode( int data ) 	// Function to create a new Node in heap
{
	BSTNode* newNode = new BSTNode( );
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	
	return newNode;
}
//-------------------------------------------------------------------------------------------
BSTNode* Insert( BSTNode* root, int data ) 				// Insert node in BST, returns address of root node 
{
	if( root == NULL ) 									// empty tree
		root = GetNewNode( data );

	else if( data <= root->data ) 						// if data is < root, insert in left subtree
		root->left = Insert( root->left, data );
	else 												// if data is > root, insert in right subtree
		root->right = Insert( root->right, data );

	return root;
}
//-------------------------------------------------------------------------------------------
bool Search( BSTNode* root, int data )   // Search given node in BST, returns true if node is found
{
	if( root == NULL )					// if root is NULL, return false
		return false;

	else if( root->data == data ) 		// if root node is equal to node to be searched, return true
		return true;

	else if( root->data >= data ) 		// if data is <= root node, search node in left subtree
		return Search(root->left, data);

	else 								// if data is > root node, search node in right subtree
		return Search( root->right, data );

}
//-------------------------------------------------------------------------------------------
BSTNode* FindMin(BSTNode* root)			// Function to find minimum in a tree.
{
	while( root->left != NULL )
	{
		root = root->left;
	}
	return root;
}
//-------------------------------------------------------------------------------------------
BSTNode* FindMax( BSTNode* root )		// Function to find maximum in a tree. 
{
	while( root->right != NULL )
	{
		root = root->right;
	}
	return root;
}
//-------------------------------------------------------------------------------------------
BSTNode* Delete( BSTNode *root, int data ) 			// Function to search a delete a value from tree.
{
	if( root == NULL )								// Empty tree
		return root;
	
	else if( data < root->data ) 
		root->left = Delete( root->left,data );
	
	else if( data > root->data ) 
		root->right = Delete( root->right,data );
	// root is the target to delete	
	else 
	{
		if( root->left == NULL && root->right == NULL ) 		// Case 1:  No child
		{ 
			delete root;
			root = NULL;
		}
		else if( root->left == NULL ) 		//Case 2: One child 
		{
			struct BSTNode *temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL ) 
		{
			struct BSTNode *temp = root;
			root = root->left;
			delete temp;
		}
		else 								//Case 3: two children 
		{
			BSTNode *temp = FindMin( root->right );
			root->data = temp->data;
			root->right = Delete( root->right, temp->data );
		}
	}
	return root;
}
//-------------------------------------------------------------------------------------------
void PreOrder( BSTNode *root ) 			// Function for Pre-order traversal
{
	if( root == NULL )					// Empty tree
		return;
 	else								// Pre-order traversal
	{
		cout << root->data;
		cout << " ";
		PreOrder ( root->left );
		PreOrder ( root->right );
	}
}
//-------------------------------------------------------------------------------------------
void InOrder( BSTNode *root ) 			// Function for In-order traversal
{
	if( root == NULL )					// Empty tree
		return;
 	else								// In-order traversal
	{
		InOrder( root->left );       	// Visit left subtree
		cout << root->data; 		   	// Print data
		cout << " ";
		InOrder( root->right );      	// Visit right subtree
	}
}
//-------------------------------------------------------------------------------------------
void PostOrder( BSTNode *root ) 		// Function for PostOrder traversal
{
	if( root == NULL )					// Empty tree
		return;
	else								// Post-order traversal
	{
		PostOrder( root->left );
		PostOrder( root->right );
		cout << root->data; 
		cout << " ";	
	}	

}
//=====================================================================================
int main( ) 
{
	int value, option;
	BSTNode* root = NULL;  // Creating an empty tree
	
	Menu:
	cout << endl << "Binary Search Tree Implementation" << endl;
	cout << "--------------------------------" << endl;
	cout << "1.  Insert"       << endl;
	cout << "2.  Delete"       << endl;
	cout << "3.  Search"       << endl;
	cout << "4.  Pre-order"    << endl;
	cout << "5.  In-order"     << endl;
	cout << "6.  Post-order"   << endl;
	cout << "7.  Menu"         << endl;
	cout << "8.  Clear screen" << endl;
	cout << "9.  Exit"         << endl;
	cout << "--------------------------------" << endl;
	
	YourOption:
	cout << endl << "Your option: ";
	cin >> option;
	cout << endl;
	
	switch(option)
	{
		case 1:
			// Insert
			cout << "Enter value to Insert: ";
			cin  >> value;
			if ( Search ( root, value ) == true )
			{
				cout << "The node " << value << " already exists in the tree!";
			}
			else
			{
				root = Insert( root, value );	
			}
			goto YourOption;

		case 2:
			// Delete
			if ( root == NULL )
				cout << "The tree is empty!";
			else
			{
				cout << "Enter value to Delete: ";
				cin  >> value;
				if ( Search ( root, value ) == false )
					cout << "The node " << value << " is not found in the tree!";
				else
					root = Delete( root, value );	
			}
			goto YourOption;	
			
		case 3:
			// Search
			if ( root == NULL )
				cout << "The tree is empty!";
			else
			{
				cout << "Enter value to Search: ";
				cin  >> value;
				if ( Search( root, value ) == true )
				{
					cout << "The node " << value << " is found in the tree!";
				}
				else
					cout << "The node " << value << " is not found in the tree!";
			}	
			goto YourOption;
				
		case 4:
			if ( root == NULL )
				cout << "The tree is empty!";
			else
			{
				PreOrder(root);		// Pre-order traversal
			}	
			goto YourOption;
				
		case 5:
			if ( root == NULL )
				cout << "The tree is empty!";
			else
			{
				InOrder( root );	// In-order traversal
			}	
			goto YourOption;
		
		case 6:
			if ( root == NULL )	
				cout << "The tree is empty!";
			else
			{
				PostOrder(root);	// Post-order traversal
			}	
			goto YourOption;
	
		case 7:
			goto Menu;				// go to the label Menu
			
		case 8:
			system("cls");			// clear screen
			goto Menu;	
			
		case 9:
			exit(0);				// Exit program
			
		default:
			cout << "Invalid option!" << endl;
			break;
	}
	return 0;
}