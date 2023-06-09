#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

extern void cpyia(int old_array[],int new_array[],int length);

int main(){

	int old_array[5] = {-1,-1,-1,-1,-1};

	int new_array[5];

	int length = 5;

	cpyia(old_array,new_array,length);
	
	return 0;
	
}