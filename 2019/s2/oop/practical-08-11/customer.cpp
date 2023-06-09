#include <string>
#include <iostream>
#include "customer.h"

using namespace std;

customer::customer(){
	name = "ABC";
	address = "ABC Street";
	membership = false;
}

customer::customer(string cName, string cAddress, bool cMembership){
	name 		= cName;
	address 	= cAddress;
	cMembership = membership;
}

string customer::getName(){
	return name;
}

string customer::getAddress(){
	return address;
}

bool customer::getMembership(){
	return membership;
}

customer::~customer(){
	
}