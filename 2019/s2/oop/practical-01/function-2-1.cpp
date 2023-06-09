#include <iostream>
#include <stdlib.h>

// function to find the minimum (smallest) number and return it. 
// The function should return 0 if the size parameter, n, is less than 1.
int minimum(int array[], int n)
{
	if (n < 1){
		return 0;
	}

	int smallest = array[0];
	
	for (int i = 0; i < n; i++)
	{
		if (smallest > array[i]){
			smallest = array[i];
		}
	}

	return smallest;
}
