#include <iostream>
#include <stdlib.h>
using namespace std;

extern int *readNumbers(int n) ;
extern int *mergeArrays(int* A, int* B, int length) ; 

int main(){

	int *A;
	int *B;
	int length = 5;
	int n = 5;

	A = readNumbers(n);
	B = readNumbers(n);
	mergeArrays(A,B,length);

	delete[] A;
	delete[] B;

}