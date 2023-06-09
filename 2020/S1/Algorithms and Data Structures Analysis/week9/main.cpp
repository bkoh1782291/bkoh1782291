
#include <iostream> 
#include <string>
#include <sstream>
#include "BinarySearchTree.h"
#include "Heap.h"
using namespace std;

int main() 
{ 
	BinarySearchTree bst, *root = NULL; 

    string input;
    getline(cin,input);

    stringstream str_strm;
    str_strm << input;
    
    string temp_str;
    int temp_int;
    string sss;

	int index = 0;
	int arr[10];
	int num =0;

	string flag;

    while(!str_strm.eof()){
    	if(index == 0)
    	{
	       str_strm >> temp_str;
	       if(stringstream(temp_str) >> sss){
	       flag = sss;
	       index++;
           }
    	}
        else if ( index > 0) 
        {
           str_strm >> temp_str;
           if(stringstream(temp_str) >> temp_int){
           arr[num] = temp_int;
           num++;
           temp_str = "";
        	}
    	}	
    }	

    //sets the first element
    root = bst.Insert(root, arr[0]);

    for (int i=1; i<num; i++){
    	bst.Insert(root, arr[i]);
    }

    //heap stuff
    int n = sizeof(arr) / sizeof(arr[0]); 

    //calls the function depending on the first input
   	if (flag == "BIN"){
		bst.Inorder(root); 	
	}
	else if (flag == "BPR"){
		bst.Preorder(root);
	}
	else if (flag == "BPO"){
		bst.Postorder(root);
	}
	else if (flag == "HS"){
		//calling heap constructor
		Heap heap(arr,num);

		for (int i=0; i<num; i++){
			cout << heap.deleteMin() << " ";
		}
	}

	cout << endl; 
	return 0; 
} 


