#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using namespace std;

class Animal{
public:
	Animal(string aSpecies);
	void set_name(string aName);

	string get_species();      
	string get_name();
	int get_ID();

	static int currentID;

	string species;
	string name;
	int id;
};

#endif