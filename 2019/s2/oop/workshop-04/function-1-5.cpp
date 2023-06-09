#include <stdlib.h>
#include <iostream>

int size_of_array_arr(){
	// Declare the variables
	int *arr = new int[3];

	return sizeof(int[3]);

	// 1.7 Stored in the Heap cause it is dynamically allocated (new operator)
	// 1.9 Can accidentally override other variable data/ other program's data	
	// 1.10 No the memory does not gets automatically freed for CPP

	// 1.11 Stackoverflow, Memory Leak etc.
	
}