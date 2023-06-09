#include <iostream>
#include <stdlib.h>

extern int sum_array(int array[], int n);

int main()
{
	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	double n = 10;

	std::cout << sum_array(array,n) << std::endl;
	return 0;
}