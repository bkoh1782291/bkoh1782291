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

int* mergeArrays(int* A, int* B, int length){

	for (int i = 0; i < length; i++){
		cout << *(A+i) << " ";
		
	}

	for (int i = 0; i < length; i++){
		cout << *(B+i) << " ";
	}
	
	cout << endl;

} 
