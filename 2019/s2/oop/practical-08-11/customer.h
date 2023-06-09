#ifndef CUS_H
#define CUS_H

#include <string>
#include <iostream>

using namespace std;

class customer{
public:
	customer();
	customer(string name, string address, bool membership);

	// Getters
	string getName();
	string getAddress();
	bool getMembership();

	// Variables
	string name;
	string address;
	bool membership;

	// Destructors
	~customer();
};

#endif //CUS_H