#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

using namespace std;

class product{
public:
	product();
	product(string pName, double pPrice, int pCurrentStock, int pId);

	// Getters
	int getId();
	string getName();
	double getPrice();
	int getCurrentStock();

	// Setters
	void setName(string pName);
	void setPrice(double pPrice);
	void setStock(int pStock);

	// Variables
	int id;
	string name;
	double price;
	int currentStock;

	// Destructors
	~product();
};

#endif //PRODUCT_H