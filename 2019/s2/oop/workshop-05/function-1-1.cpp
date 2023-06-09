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


void printNumbers(int *numbers,int length){

	cout << "your numbers are :" << endl;
	for (int i = 0; i<length; i++){
		cout << i << " "; 
		cout << *(numbers+i) << endl;;
	}


}