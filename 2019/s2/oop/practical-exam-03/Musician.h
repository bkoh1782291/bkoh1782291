#ifndef MUSICIAN_H
#define MUSICIAN_H

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Musician{
public:

	Musician();
	Musician(string instrument, int experience);
	string get_instrument();
	int get_experience();   
	~Musician(); 

	string newInstrument;
	int newExperience;
};

#endif 