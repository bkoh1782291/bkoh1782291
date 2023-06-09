#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

extern int *readNumbers();
extern void printNumbers(int *numbers,int length);
extern void hexDigits(int *numbers,int length);

int main(){

	int *numbers;
	int length = 10;

	numbers = readNumbers();
	printNumbers(numbers,length);
	hexDigits(numbers,length);


	return 0;
}