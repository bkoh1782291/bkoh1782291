#include <iostream>
#include <string>
#include "Animal.h"

using namespace std;

int Animal::currentID = 0;

Animal::Animal(string aSpecies){
	id = currentID++;
	species = aSpecies;

}

void Animal::set_name(string aName){
	name = aName;

}

string Animal::get_species(){
	return species;

}

string Animal::get_name(){
	return name;

}

int Animal::get_ID(){
	return id;

}