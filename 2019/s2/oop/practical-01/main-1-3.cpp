#include <iostream>
#include <stdlib.h>

extern int count(int array[] ,int n ,int num);

int main()
{
	int array[10] = {1,0,3,4,5,6,7,8,9,10};
	int n = 10;
	int num = 5;

	std::cout << count(array,n,num) << std::endl;
	return 0 ;
}

