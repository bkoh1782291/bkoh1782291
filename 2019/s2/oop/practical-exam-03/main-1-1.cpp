#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Musician.h"

using namespace std;

int main(){
	
	Musician a1;

	a1 = Musician("Guitar ",5);

	//Instrument1 = get_instrument("guitar");

	//Experience1 = get_experience("5")

	//cout << Instrument1 << endl;

	//cout << Experience1 << endl;

	string instrument1 = a1.get_instrument();

	int experience1 = a1.get_experience();
	
	cout << instrument1 << endl;

	cout << experience1 << endl;

	return 0;
}