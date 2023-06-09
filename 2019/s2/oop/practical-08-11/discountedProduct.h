#ifndef DPRODUCT_H
#define DPRODUCT_H

#include <string>
#include <iostream>
#include "product.h"

using namespace std;

class discountedProduct :public product{
public:
	discountedProduct(int dId, double pPrice);

	// Getters
	int getId();
	double getPrice();

	int id;
	double price;

	// Destructors
	~discountedProduct();
};

#endif //DPRODUCT_H