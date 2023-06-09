#include <iostream>
#include <stdlib.h>

extern bool descending(int*,int);

int main()
{
	int array[5] = {1,2,3,4,5};
	int n = 5;

	std::cout << descending(array,n) << std::endl;
	return 0 ;
}
