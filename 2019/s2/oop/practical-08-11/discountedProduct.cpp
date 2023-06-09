#include <string>
#include <iostream>
#include "discountedProduct.h"

/*discountedProduct::discountedProduct(){
	id   		 = id++;
	name 		 = "Product";
	price 		 = 10.01 ;
	currentStock = 5;
}*/

discountedProduct::discountedProduct(int dId, double pPrice){
	id 				= dId;
	price 			= pPrice;
}

double discountedProduct::getPrice(){
	return price * 0.90;
}

int discountedProduct::getId(){
	return id;
}