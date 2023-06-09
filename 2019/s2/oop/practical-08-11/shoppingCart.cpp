#include <string>
#include <iostream>
#include <vector>
#include "shoppingCart.h"

using namespace std;

shoppingCart::shoppingCart(){
	totalPrice = 0.00;
	totalItems = 0;
	count = 0;
}

double shoppingCart::getTotalPrice(){
	return totalPrice;
}

int shoppingCart::getTotalItems(){
	return totalItems;
}

void shoppingCart::setTotalPrice(double sTotalPrice){
	totalPrice = sTotalPrice;
}

void shoppingCart::setTotalItems(int sTotalItems){
	totalItems = sTotalItems;
}

bool shoppingCart::addItem(int sId){
	bool check = true;

	if (totalItems == 5){
		check = false;
	} else {
			myVector.push_back(sId);
			totalItems++;
	}

	return check;
}

void shoppingCart::removeItem(int sId){

	for(int i = 0; i < totalItems; i++){
		if (myVector[i] == sId){
			myVector.erase(myVector.begin() + i);
		}
	}
	
	totalItems--;
	
}

void shoppingCart::clearCart(){
		myVector.clear();
}