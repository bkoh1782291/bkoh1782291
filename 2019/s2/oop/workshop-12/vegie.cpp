#include <iostream>
#include <string>
#include "vegie.h"

int vegie::nextID = 100;

vegie::vegie(string n,int v):animal(n,v){
	favourite_food = "grass";
	name = n;
	volume = v;
	id = nextID++;
}

string vegie::get_name(){
	return "Safe: " + name;
}
string vegie::get_favourite_food(){
	return favourite_food;
}

void vegie::set_favourite_food(string vFood){
	favourite_food = vFood;
}