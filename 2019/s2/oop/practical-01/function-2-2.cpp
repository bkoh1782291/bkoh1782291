#include <iostream>
#include <stdlib.h>

// function to find maximum

int maximum(int array[], int n)
{
	if (n < 1){
		return 0;
	}

	int largest = array[0];
	for (int i = 0; i < n; i++)
	{
		if (largest < array[i]){
			largest = array[i];
		}
	}

	return largest;
}
