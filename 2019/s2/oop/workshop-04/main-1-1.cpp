#include <stdlib.h>
#include <iostream>

extern int size_of_variable_star_t();

int main(){
	int tValue = 0;

	tValue = size_of_variable_star_t();

	std::cout << tValue;
	std::cout << std::endl;
}