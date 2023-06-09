#include <string>
#include <iostream>
#include "product.h"

product::product(){
	id   		 = 1;
	name 		 = "Product";
	price 		 = 10.01 ;
	currentStock = 5;
}

product::product(string pName, double pPrice, int pCurrentStock, int pId){
	name 			= pName;
	price 			= pPrice;
	currentStock 	= pCurrentStock;
	id 				= pId;
}

string product::getName(){
	return name;
}

double product::getPrice(){
	return price;
}

int product::getCurrentStock(){
	return currentStock;
}

int product::getId(){
	return id;
}

void product::setName(string pName){
	name = pName;
}

void product::setPrice(double pPrice){
	price = pPrice;
}

void product::setStock(int pStock){
	currentStock = pStock;
}

product::~product(){

}

/*
// Getters
int getid();
string getName();
double getPrice();
int getCurrentStock();

// Setters
void setName(string pName);
void setPrice(double pPrice);
void setStock(int pStock);
*/