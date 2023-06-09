#include <iostream>
#include <stdlib.h>


extern void count_numbers(int array[4][4]);

int main(){

	int array[4][4] = {{1,2,3,4}, {5,6,7,2}, {9,8,2,6}, {5,4,3,2}};

	count_numbers(array);

}