#include <stdlib.h>
#include <iostream>

int size_of_variable_star_arr(){
	// Declare the variables
	int *arr = new int[3];
	//arr[1] = 5;
	delete arr;
	std::cout << sizeof(arr);

	return 0;	
}