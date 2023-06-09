#include <iostream>
#include <stdlib.h>

// function that returns the number of elements in an array that are equal to a given parameter.
int count(int array[], int n, int num)
{

	if (n < 1){
		return 0;
	}

	int count = 0;

	for (int i = 0; i < n; i++){
		if (array[i] == num){
		count ++;
		}
	}

	return count;
}
