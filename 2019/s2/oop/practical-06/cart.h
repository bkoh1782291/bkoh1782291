#ifndef CART_H
#define CART_H

#include "meerkat.h"
#include <iostream>
#include <string>

using namespace std;

class cart{

public:
	cart();                        
	bool addMeerkat(meerkat cat);  
	void emptyCart();             
	void printMeerkats();

	int age[5];
	string names[5];
	int count;

};

#endif //CART_H
