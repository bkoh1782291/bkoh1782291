#include <iostream>
#include <stdlib.h>
using namespace std;

int *readNumbers(int n){

	int *array = new int[n];
	
	for (int i =0; i<n; i++){
		cin >> array[i];
	}
	return array;
}

void months(int* monthNumbers,int length){

	for(int i =0 ; i < length; i++){
		cout << i << " ";
		switch(*(monthNumbers+i)){
			case 1:
				cout << "1" <<" "<< "January" << endl;
			break;
			case 2:
				cout << "2" <<" "<< "Febuary" << endl;
			break;
			case 3:
				cout << "3" <<" "<< "March" << endl;
			break;
			case 4:
				cout << "4" <<" "<< "April" << endl;
			break;
			case 5:
				cout << "5" <<" "<< "May" << endl;
			break;
			case 6:
				cout << "6" <<" "<< "June" << endl;
			break;
			case 7:
				cout << "7" <<" "<< "July" << endl;
			break;
			case 8:
				cout << "8" <<" "<< "August" << endl;
			break;
			case 9:
				cout << "9" <<" "<< "September" << endl;
			break;
			case 10:
				cout << "10" <<" "<< "October" << endl;
			break;
			case 11:
				cout << "11" <<" "<< "November" << endl;
			break;
			case 12:
				cout << "12" <<" "<< "December" << endl;
			break;
		}
	}

	
}






