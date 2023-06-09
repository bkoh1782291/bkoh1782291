#include <string>
#include <iostream>
#include "animal.h"

using namespace std;

animal::animal(string n, int v){
	name = n;
	volume = v;
	animalID = id++;
}

int animal::get_animalID(){
	return animalID;
}
int animal::get_volume(){
	return volume;
}

void animal::set_name(string aName){
	name = aName;
}
void animal::set_volume(int aVolume){
	volume = aVolume;
}

animal::~animal(){

}