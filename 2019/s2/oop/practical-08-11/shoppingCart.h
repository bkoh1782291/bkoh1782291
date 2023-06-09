#ifndef CART_H
#define CART_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class shoppingCart{
public:
	shoppingCart();

	// Getters
	double getTotalPrice();
	int getTotalItems();
	
	// Setters
	void setTotalPrice(double sTotalPrice);
	void setTotalItems(int sTotalItems);

	// Functions
	bool addItem(int sId);
	void removeItem(int sId);
	void clearCart();

	// Variables
	vector<int> myVector;
	double totalPrice;
	int totalItems;
	int count;

	// Destructors
	~shoppingCart();
};

#endif //CART_H