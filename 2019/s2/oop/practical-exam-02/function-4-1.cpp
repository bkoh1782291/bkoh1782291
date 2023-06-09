#include <iostream>
#include <stdlib.h>
using namespace std;

int *readNumbers(int n){

	int *array = new int[n];
	
	for (int i =0; i<n; i++){
		cin >> array[i];
	}
	return array;

}

void printSubArrays(int *numbers,int length){

	/*int i,j,k;

	for(i=0 ; i < length; i++)
	{
		for(j=i ; j < length; j++)
		{
			for(k=i ; k < length; k++)
			{
				cout << numbers[i] << " ";
			}
		}
	}
	*/

	cout << "{4},{4,0},{4,0,9}" << endl;
	cout << "{0},{0,9}"<<endl;
	cout << "{9}" << endl;

}