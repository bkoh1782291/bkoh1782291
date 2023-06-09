#include <iostream>
#include <stdlib.h>

//  count the number of even numbers between 1 and a number 
int count_even(int number)
{
	int count = 0;

	for (int i = 0; i < number; i++){
		if (i % 2 == 0){
			count++;
		}
	}
	return count;
}
