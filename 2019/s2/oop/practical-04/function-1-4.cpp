#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

void cpyda(double *old_array,double *new_array,int length){

	double *ptr;
	double *a = new double[length];

	ptr = old_array;

	a = ptr;

	new_array = a;

	for (int i = 0; i < length; i++)
	{
		cout << new_array[i] << " ";
	}

	cout << endl;
}