#include <iostream>
#include <string>
#include "hunter.h"


using namespace std;

int hunter::nextID = 1000;

hunter::hunter(string n, int v) : animal(n, v){
	name = n;
	volume = v;
	id = nextID++;
}

string hunter::get_name(){
	return "Hunter: " + name;
}

int hunter::get_kills(){
	return kills;
}

void hunter::set_kills(int hKills){
	kills = hKills;
}