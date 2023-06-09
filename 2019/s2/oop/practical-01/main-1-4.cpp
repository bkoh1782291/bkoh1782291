#include <iostream>
#include <stdlib.h>

extern int sumtwo(int array[] ,int secondarray[] ,int n);

int main()
{
	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	int secondarray[10] = {10,9,8,7,6,5,4,3,2,1};
	int n = 10;

	std::cout << sumtwo(array,secondarray,n) << std::endl;

	return 0 ;
}
