#include <stdlib.h>
#include <iostream>

extern int size_of_array_arr();

int main(){
	int arrValue = 0;

	arrValue = size_of_array_arr();

	std::cout << arrValue;
	std::cout << std::endl;
}