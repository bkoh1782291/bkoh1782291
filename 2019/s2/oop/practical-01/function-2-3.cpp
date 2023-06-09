#include <iostream>
#include <stdlib.h>

// function to find numbers 2, 5, 9

	void twofivenine(int array[], int n)
{
	if (n < 1){
		return;
	}

	int count1 = 0;
	int count2 = 0;
	int count3 = 0;

	for (int i = 0; i < n; i++){

		int a = array[i];
		switch(a)
		{
			case 2:
				count1++;
				break;
			case 5:
				count2++;
				break;
			case 9:
				count3++;
			break; 
		}

}

	std::cout << "2:" << count1 <<";"<<"5:"<< count2<<";"<<"9:"<<count3<<";"<< std::endl;
}
