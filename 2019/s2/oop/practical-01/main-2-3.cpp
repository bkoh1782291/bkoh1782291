#include <iostream>
#include <stdlib.h>

extern void twofivenine(int array[] ,int n);

int main(int argc,char **argv)
{
	int array[10] = {1,5,4,3,7,8,9,5,4,5};
	int n = 10;

	twofivenine(array,n);
	
}
