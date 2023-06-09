#include <stdlib.h>
#include <iostream>

extern float arithmetic_ops(float left, float right, std::string op);

int main(){
	float left = 5;
	float right = 11;
	std::string op = "+";

	float result = 0;

	result = arithmetic_ops(left,right,op);
	std::cout << result;
	std::cout << std::endl;

	// 2.2 Add more functions and add more if else to the arithmetic_ops
	
}