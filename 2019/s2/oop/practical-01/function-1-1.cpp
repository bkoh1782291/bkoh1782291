#include <iostream>
#include <stdlib.h>

int sum_array(int array[], int n)
{
	if (n < 1){
		return 0;
	}

	int sum = 0; 
	
	for (int i = 0; i < n; i++)
	{
		sum = sum + array[i];
	}

	return sum;
}