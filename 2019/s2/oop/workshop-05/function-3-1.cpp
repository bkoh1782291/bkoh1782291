#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

int *readNumbers(){
	int *array = new int[10];

	cout << "Please enter 10 numbers" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> array[i];
	}
	return array;
}

bool equalsArray(int *numbers1,int *numbers2,int length){

	for (int i = 0; i < length; i++){

		if(numbers1[i]!=numbers2[i])
        {
            return false;
        }
	}

		delete[] numbers1;
	    delete[] numbers2;
    
    return true;
	
}
