#include <stdio.h>
#include <stdlib.h>
// Node structure
typedef struct Node 
{
   int key;
   struct Node *left, *right;
   int height;
} Node;
//-------------------------------------------------------------------------------------------
// Function to get the height of a node
int height(Node *node) 
{
   return node ? node->height : 0;
}
//-------------------------------------------------------------------------------------------
// Function to calculate balance factor
int getBalance(Node *node) 
{
   return node ? height(node->left) - height(node->right) : 0;
}
//-------------------------------------------------------------------------------------------
// Create a new node
Node* createNode(int key) 
{
   Node* node = (Node*)malloc(sizeof(Node));
   node->key = key;
   node->left = node->right = NULL;
   node->height = 1; // New node is initially at height 1
   return node;
}
//-------------------------------------------------------------------------------------------
// Right rotation
Node* rightRotate(Node *y) 
{
   Node *x = y->left;
   Node *T2 = x->right;
   // Perform rotation
   x->right = y;
   y->left = T2;
   // Update heights
   y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
   x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
   return x; // New root
}
//-------------------------------------------------------------------------------------------
// Left rotation
Node* leftRotate(Node *x) 
{
   Node *y = x->right;
   Node *T2 = y->left;
   // Perform rotation
   y->left = x;
   x->right = T2;
   // Update heights
   x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
   y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
   return y; // New root
}
//-------------------------------------------------------------------------------------------
// Insert a key into the AVL tree
Node* insert(Node* node, int key) 
{
   if (!node)
       return createNode(key);
       
   if (key < node->key)
       node->left = insert(node->left, key);
   else if (key > node->key)
       node->right = insert(node->right, key);
   else
       return node; 							// Duplicate keys are not allowed
   // Update the height of this ancestor node
   node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
   // Get the balance factor to check if this node became unbalanced
   
   int balance = getBalance(node);						 // Perform rotations to balance the tree
  
   
   if (balance > 1 && key < node->left->key)
       return rightRotate(node); 						// Left-Left case
       
   if (balance < -1 && key > node->right->key)
       return leftRotate(node); 						// Right-Right case
       
   if (balance > 1 && key > node->left->key) 
   {
       node->left = leftRotate(node->left); 			// Left-Right case
       return rightRotate(node);
       
   }
   
   if (balance < -1 && key < node->right->key) 
   {
       node->right = rightRotate(node->right);			// Right-Left case
       return leftRotate(node);
   }
   
   return node; // Return unchanged pointer if balanced
}
//-------------------------------------------------------------------------------------------
// In-order traversal of the AVL tree
void inOrder(Node *root) 
{
   if (root != NULL) {
       inOrder(root->left);
       printf("%d ", root->key);
       inOrder(root->right);
   }
}
//=======================================================================================
int main() 
{
   Node *root = NULL;
   
   root = insert(root, 10);
   root = insert(root, 20);
   root = insert(root, 30);
   root = insert(root, 40);
   root = insert(root, 50);
   root = insert(root, 25);
   printf("In-order traversal of the AVL tree: ");
   inOrder(root);
   
   return 0;
}
