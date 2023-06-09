#include <stdlib.h>
#include <iostream>

extern float subtract_op(float left, float right);
extern float add_op(float left, float right);

float arithmetic_ops(float left, float right, std::string op){
	
	if (op == "+"){
		return add_op(left, right);
	} else if(op == "-"){
		return subtract_op(left, right);
	} else {
		return -1;
	}
}

float subtract_op(float left, float right){
	return left - right;
}

float add_op(float left, float right){
	return left + right;
}