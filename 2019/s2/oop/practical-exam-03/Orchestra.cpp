#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Musician.h"
#include "Orchestra.h"

using namespace std;

Orchestra::Orchestra(){
	sizeofOrchestra = 0;
}

Orchestra::Orchestra(int size){
	sizeofOrchestra = size;
	//instrument_check = instrument;
	//newMusician = new_musician;
}

int Orchestra::get_current_number_of_members(){
	sizeofOrchestra ++;
	return sizeofOrchestra;
}


bool Orchestra::has_instrument(string instrument){
	return instrument_check;
}

Musician *Orchestra::get_members(){
 	return Members;
}  

bool Orchestra::add_musician(Musician new_musician){
	return newMusician;
}

Orchestra::~Orchestra(){
}