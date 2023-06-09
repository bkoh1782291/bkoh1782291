#include <iostream>
#include <stdlib.h>
using namespace std;

extern int *readNumbers(int n) ;
extern bool twinArray(int* numbers, int length);

int main(){

	int *numbers;
	int length = 6;
	int n = 6;

	numbers = readNumbers(n);
	cout << twinArray(numbers,length) << endl;

	delete[] numbers;

}
