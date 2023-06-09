#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Musician.h"

using namespace std;

Musician::Musician(){
	newInstrument = "NULL";
	newExperience = 0;
}

Musician::Musician(string instrument, int experience){
	newInstrument = instrument;
	newExperience = experience;
}

string Musician::get_instrument(){
	return newInstrument;
}

int Musician::get_experience(){
	return newExperience;
} 

Musician::~Musician()
{
}