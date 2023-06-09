#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

extern int *readNumbers();
extern bool equalsArray(int *numbers1,int *numbers2,int length);
extern int *reverseArray(int *numbers1,int length);

int main(){

	int *numbers1 = readNumbers();
	int length = 10;

	int *numbers2 = readNumbers();

	reverseArray(numbers1,length);

	cout << endl;

	cout << equalsArray(numbers1,numbers2,length) << endl;


}

