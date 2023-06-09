#include <iostream>
#include <stdlib.h>
using namespace std;

extern int *readNumbers(int n) ;
extern void months(int* monthNumbers,int length) ;


int main(){

	int *monthNumbers;
	int length = 5;
	int n = 5;

	monthNumbers = readNumbers(n);
	months(monthNumbers,length);


	delete[] monthNumbers;

}