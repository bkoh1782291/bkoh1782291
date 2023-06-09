#include <iostream>
#include <stdlib.h>

// function to determine whether an array is in ascending order
bool ascending(int array[], int n)
{
	int current_num = array[0];

	for (int i = 0; i < n; i++){
		if (array[i] >= current_num)
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
