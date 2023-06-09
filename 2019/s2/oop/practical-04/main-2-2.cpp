#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

extern int maximum_sum(int *nums,int length);

int main(){

	int nums[10] = {31,-41,59,-26,53,-58,97,-93,23,-84};

	int length = 10;

	cout << maximum_sum(nums,length) << endl;

	return 0;
}