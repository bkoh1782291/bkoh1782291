#include <string>
#include <iostream>
#include "streetMarket.h"

using namespace std;

streetMarket::streetMarket(string name){
	branchName = name;
	discountCode = "SM123";
}

string streetMarket::getDiscountedCode(){
	return discountCode;
}

streetMarket::~streetMarket(){

}

