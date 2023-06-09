#include <iostream>
#include <stdlib.h>
using namespace std;

extern int *readNumbers(int n) ;
extern void printNumbers(int *numbers,int length) ;

int main(){

	int *numbers;
	int length = 5;
	int n = 5;

	numbers = readNumbers(n);
	printNumbers(numbers,length);

	delete[] numbers;
}
