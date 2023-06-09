#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

int maximum_sum(int *nums,int length){

	int maximum = 0;
	int numbcount = 0;

	for (int i = 0; i<length ; i++)
	{
		numbcount = numbcount + nums[i];
		
		if (maximum < numbcount)
			maximum = numbcount;
		else if (numbcount < 0)
			numbcount = 0;
	}
	return maximum;

}