#include <iostream>
#include <stdlib.h>

// return sum of elements in matrix diagonally (from top left to bottom right)

extern int diagonal(int array[4][4]);

int main(){

	int array[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,8,7,6}, {5,4,3,2}};

	std::cout << diagonal(array) << std::endl;

	return 0;
}

