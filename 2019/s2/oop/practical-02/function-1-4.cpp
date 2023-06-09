#include <iostream>
#include <stdlib.h>

// multiply every element in the matrix by the same numeric value
void print_scaled_matrix(int array[3][3],int scale){


	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			array[i][j] = scale*(array[i][j]);

		}
	}

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
		std::cout << array[i][j] << " " ;
		}
		std::cout << std::endl;;
	}	



}