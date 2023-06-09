#include <iostream>
#include <stdlib.h>

extern void printer(int array[10][10]);

int main(int argc,char **argv)
{
	int array[10][10];
	int result;
	
	for(int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (i == j){
				array[i][j] = 1;
			} else {
				array[i][j] = 0;
			}
			//std::cout << array[i][j];
		}
		//std::cout << std::endl;
	}

	printer(array);

}