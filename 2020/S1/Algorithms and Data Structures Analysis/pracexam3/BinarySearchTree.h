#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class BinarySearchTree 
{ 
	int data; 
	BinarySearchTree *left, *right; 

	public: 
	
	// Default constructor. 
	BinarySearchTree(); 
	BinarySearchTree(int); 
	
	// Insert function. 
	BinarySearchTree* Insert(BinarySearchTree *, int); 
	
	// Inorder print
	void Inorder(BinarySearchTree *); 

	// Preorder print
	void Preorder(BinarySearchTree *);

	// postorder print
	void Postorder(BinarySearchTree *);

}; 

#endif