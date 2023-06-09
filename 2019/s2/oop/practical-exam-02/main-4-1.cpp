#include <iostream>
#include <stdlib.h>
using namespace std;

extern int *readNumbers(int n) ;
extern void printSubArrays(int *numbers,int length);

int main(){

	int *numbers;
	int length = 3;
	int n = 3;

	numbers = readNumbers(n);
	printSubArrays(numbers,length);

}