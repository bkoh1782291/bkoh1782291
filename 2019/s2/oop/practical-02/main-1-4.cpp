#include <iostream>
#include <stdlib.h>

extern void print_scaled_matrix(int array[3][3],int scale);

int main(){

	int scale = 3;

	int array[3][3] = {{0,1,2}, {3,4,5}, {6,7,8}};

	print_scaled_matrix(array, scale);
}