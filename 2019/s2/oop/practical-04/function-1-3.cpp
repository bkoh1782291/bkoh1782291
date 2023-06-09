#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

void cpyia(int old_array[],int new_array[],int length){
	
	int *ptr;
	int *a = new int[length];

	ptr = &old_array[0];

	a = ptr;

	new_array = a;

	for (int i = 0; i < length; i++)
	{
		cout << new_array[i];
	}

	cout << endl;
}