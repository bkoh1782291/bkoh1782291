#include <string>
#include <iostream>
#include "membershipMarket.h"

using namespace std;

membershipMarket::membershipMarket(string aBranchName){
	branchName = aBranchName;
	discountCode = "MM123";
}

string membershipMarket::getDiscountedCode(){
	return discountCode;
}

membershipMarket::~membershipMarket(){
	
}
