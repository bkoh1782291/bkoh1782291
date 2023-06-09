#ifndef STREETMARKET_H
#define STREETMARKET_H

#include <string>
#include <iostream>
#include "market.h"

using namespace std;

class streetMarket :public market{
public:
	streetMarket(string name);

	// Getters
	virtual string getDiscountedCode() override;

	string branchName;
	string discountCode;

	// Destructors
	~streetMarket();
};

#endif //STREETMARKET_H