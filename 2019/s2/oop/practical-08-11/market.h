#ifndef MARKET_H
#define MARKET_H

#include <string>
#include <iostream>

using namespace std;

class market{
public:
	// Virtual Method
	virtual string getDiscountedCode() =0;
};

#endif //MARKET_H