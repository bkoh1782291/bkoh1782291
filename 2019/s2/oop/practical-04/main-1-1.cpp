#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

extern void copy_2d_strings(string first[][2], string second[][2], int n);

int main(){

	string first[3][2] = {"0","0","0","0","1","1"};
	
	string second[3][2] = {"1","2","3","4","5","6"};

	int n = 3;

	copy_2d_strings(first,second,n);
	
	return 0;
}