#include <iostream>
#include <stdlib.h>

// function to see whether an array is descending
bool descending(int array[], int n)
{
	int current_num = array[0];

	for (int i = 0; i < n; i++){
		if (array[i] <= current_num)
		{
			current_num = array[i];
		}
		else 
		{
			return false;
		}
	}
	return true;
}
