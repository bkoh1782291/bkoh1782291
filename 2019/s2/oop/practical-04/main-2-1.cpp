#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;


extern void print_sevens(int *nums,int length);

int main(){

	int length=10;
	int array[10]={1,2,3,4,5,6,7,8,9,0};
	int* ptr = &array[0];
	print_sevens(ptr,length);
	
}