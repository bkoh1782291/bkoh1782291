#include <iostream>
#include <stdlib.h>

// returns the sum of two arrays as an integer 
int sumtwo(int array[], int secondarray[], int n)
{
	int sum = 0; 

	if (n < 1){
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
			sum = sum + (array[i] + secondarray[i]);
	}

	return sum;
}
