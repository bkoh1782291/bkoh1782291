#include <iostream>
#include <stdlib.h>
using namespace std;

int *readNumbers(int n){

	int *array = new int[n];
	
	for (int i =0; i<n; i++){
		cin >> array[i];
	}
	return array;
}

bool twinArray(int* numbers, int length){

	for (int i =0; i < length; i++){
		if (numbers[i] != numbers[i+1]){
			return false;
		}
		else{
			return true;
		}
	}
	
}