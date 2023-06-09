#include <iostream>
#include <stdlib.h>


void count_numbers(int array[4][4]){

	int count0 = 0;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int count5 = 0;
	int count6 = 0;
	int count7 = 0;
	int count8 = 0;
	int count9 = 0;

		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
					
					int a = array[i][j];
					switch(a){
						case 0:
							count0++;
							break;
						case 1:
							count1++;
							break;
						case 2:
							count2++;
							break;
						case 3:
							count3++;
							break;
						case 4:
							count4++;
							break;
						case 5:
							count5++;
							break;
						case 6:
							count6++;
							break;
						case 7:
							count7++;
							break;
						case 8:
							count8++;
							break;
						case 9:
							count9++;
							break;
					}
				}
			}

	std::cout 
	<< "0:" << count0 << ";" 
	<< "1:" << count1 << ";" 
	<< "2:" << count2 << ";" 
	<< "3:" << count3 << ";" 
	<< "4:" << count4 << ";" 
	<< "5:" << count5 << ";" 
	<< "6:" << count6 << ";" 
	<< "7:" << count7 << ";" 
	<< "8:" << count8 << ";" 
	<< "9:" << count9 << ";"
	<< std::endl;
	
}