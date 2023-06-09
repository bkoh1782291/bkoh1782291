#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

int *readNumbers(){
	int *array;
	array = new int[10];

	cout << "Please enter 10 numbers" << endl;
	for (int i = 0; i < 10; i++){
		cin >> array[i];
	}
	return array;
}

int secondSmallestSum(int *numbers,int length){



	
}