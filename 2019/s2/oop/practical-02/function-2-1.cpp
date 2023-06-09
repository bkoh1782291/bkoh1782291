#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>

void print_as_binary(std::string decimal_number){

	int binary[1000000]; 

	int number = stoi(decimal_number);

	int j = 0;

	for(int i=0; i<100; i++){
		
		if (number !=0 )
		{
		binary[j++] = number % 2;
		number = number / 2;
		}

	}

	for (int i = j-1 ; i >= 0; i-- ){

		std::cout << binary[i];
	}

	std::cout << " " << std::endl;
}