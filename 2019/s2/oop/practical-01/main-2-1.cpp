#include <iostream>
#include <stdlib.h>

extern int minimum(int array[], int n);

int main(int argc,char **argv)
{
	int array[10] = {5,4,6,2,3,5,9,2,3,10};
	int n = 10;

	std::cout << "The lowest number is " << minimum(array,n) << std::endl;
	return 0 ;
}
