#include <string>
#include <iostream>
#include "Person.h"

using namespace std;

Person::Person(string n, string o, int sl){
	name = n;
	occupation = o;
	serviceLength = sl;
	personID = id;
}

string Person::get_name(){
	return name;
}

string Person::get_occupation(){
	return occupation;
}

int Person::get_serviceLength(){
	return serviceLength;
}

int Person::get_personID(){
	return personID;
}

void Person::set_name(string aName){
	name = aName;
}

void Person::set_occupation(string aOccupation){
	occupation = aOccupation;
}

void Person::set_salary(int aSalary){
	salary = aSalary;
}

void Person::set_personID(int aPersonID){
	personID = aPersonID;
}

Person::~Person(){

}