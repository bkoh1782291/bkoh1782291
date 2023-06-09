#include <iostream>
#include <stdlib.h>

extern int count_even(int number);

int main()
{
	int number = 15;

	std::cout << count_even(number) << std::endl;
	return 0 ;
}
