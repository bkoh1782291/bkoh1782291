#ifndef MMARKET_H
#define MMARKET_H

#include <string>
#include <iostream>
#include "market.h"

using namespace std;

class membershipMarket :public market{
public:
	membershipMarket(string aBranchName);

	// Getters
	virtual string getDiscountedCode() override;

	//variables
	string branchName;
	string discountCode;

	// Destructors
	~membershipMarket();
};

#endif //MMARKET_H