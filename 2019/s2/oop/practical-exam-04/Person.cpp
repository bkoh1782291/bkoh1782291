#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

Person::Person(){

}

Person::Person(string n, string o, int sl){
	name = n;
	occupation = o;
	personID = id;
	salary = s;
}

string Person::get_name(){
	return name;
}

string Person::get_occupation(){
	return occupation;
}

int Person::get_salary(){
	if (salary <= 0){
		cout << "No negative numbers" << endl;
		salary = 0;
	} else {
		return salary;
	}
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

Person::~Person(){

}