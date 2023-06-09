#include <iostream>
#include <stdlib.h>
#include <cmath>

int binary_to_number(int binary_digits[], int number_of_digits){


	int number = 0;

	int r = 0;

	for (int i = 0; i < number_of_digits; i++){

	number = number + binary_digits[number_of_digits-i-1] * pow(2,r++);

	}

	return number;
}	
