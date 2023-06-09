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
		cout << i << " " << *(numbers+i) << endl;
	}
}

void hexDigits(int *numbers,int length){

	for (int i = 0; i< length; i++){
		if (*(numbers+i)>=10){
			switch(*(numbers+i)){
				case 10:
				cout << "A" << endl;
					break;
				case 11:
				cout << "B"<< endl;
					break;
				case 12:
				cout << "C"<< endl;
					break;
				case 13:
				cout << "D"<< endl;
					break;
				case 14:
				cout << "E"<< endl;
					break;
				case 15:
				cout << "F"<< endl;
					break;
			}
		}
		else if (0<=*(numbers+i)<=9){
				cout<< *(numbers+i) << endl;
			}
		}

	}
