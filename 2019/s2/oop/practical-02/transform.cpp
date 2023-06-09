#include <iostream>
int array(int number)
{

	for(int i=0; i<100; i++){
		if(number==0){
			break;
		}
		if(number%2==0){
			number=number/2;
			
			std::cout << "0" << std::endl;
		}
		if(number%2==1){
			number=(number-1)/2;
			
			std::cout << "1" << std::endl;
		}

	}
	std::cout << " " << std::endl;
	return 0;
}