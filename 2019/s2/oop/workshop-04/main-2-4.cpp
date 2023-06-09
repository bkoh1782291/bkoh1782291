#include <stdlib.h>
#include <iostream>

extern float arithmetic_ops(float left, float right, float (*op)(float,float));
extern float multiply_op(float left, float right);
//extern float add_op(float left, float right);
int main(){
	float left = 5;
	float right = 11;
	//std::string op = "*";
	//float multiply_op = (&op)(left,right);

	float result = 0;

	result = arithmetic_ops(left,right,multiply_op);
	std::cout << result;
	std::cout << std::endl;

	/*result = arithmetic_ops(left,right,add_op);
	std::cout << result;
	std::cout << std::endl;*/

	// 2.2 Add more functions and add more if else to the arithmetic_ops
	
}