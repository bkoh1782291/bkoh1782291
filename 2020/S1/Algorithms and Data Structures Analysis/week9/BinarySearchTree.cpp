#include <iostream>
#include "BinarySearchTree.h"
using namespace std; 

// Default Constructor 
BinarySearchTree::BinarySearchTree() : data(0), left(NULL), right(NULL){}

 
BinarySearchTree::BinarySearchTree(int number) 
{ 
	data = number; 
	left = right = NULL; 
} 

//inserts the numbers into the tree 
//returns the root value 
BinarySearchTree* BinarySearchTree::Insert(BinarySearchTree *root, int number) 
{ 
	//recursive insertion
	if(!root)   //if(root==NULL)
		return new BinarySearchTree(number); 

	// if number is more than the root
	// insert to the right
	// else insert to the left
	if(number > root->data){
		root->right = Insert(root->right, number); 
	}
	else{ 
		root->left = Insert(root->left, number); 
	}
	return root; 
} 

//Inorder print
void BinarySearchTree::Inorder(BinarySearchTree *root) 
{ 
	if(!root) 
	{ 
		return; 
	} 
	//left to root to right
	Inorder(root->left); 
	cout << root->data << " ";
	Inorder(root->right); 
} 

//preorder print
void BinarySearchTree::Preorder(BinarySearchTree *root)
{
	if (!root){
        return; 
	}
 	//root to left to right
    cout << root->data << " "; 
    Preorder(root->left);  
    Preorder(root->right); 
}

//postorder print
void BinarySearchTree::Postorder(BinarySearchTree *root)
{
	if (!root){
        return; 
	}
	// left to right to node
	Postorder(root->left);  
    Postorder(root->right); 
	cout << root->data << " "; 

}
