#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

extern void cpyda(double *old_array,double *new_array,int length);

int main(){

	double old_array[5] = {1,2,3,4,5};

	double new_array[5];

	double length = 5;

	cpyda(old_array,new_array,length);

}

