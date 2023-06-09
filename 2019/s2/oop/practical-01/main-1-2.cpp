#include <iostream>
#include <stdlib.h>

extern double average(int array[] ,int n );

int main()
{
	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	int n = 10;
	int desired_num = 4;

	std::cout << average(array,n) << std::endl;
	return 0 ;
}

