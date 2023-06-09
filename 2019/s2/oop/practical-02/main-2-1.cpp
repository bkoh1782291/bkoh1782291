#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>

extern void print_as_binary(std::string decimal_number);

int main(){

	std::string decimal_number = "43";

	print_as_binary(decimal_number);

	return 0;
}