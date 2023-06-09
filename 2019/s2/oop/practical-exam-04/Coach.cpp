#include <iostream>
#include <string>
#include "Person.h"
#include "Coach.h"

using namespace std;

int Coach::nextID = 0; 

Coach::Coach():Person("","coach",0){
}

Coach::Coach(string n, int sl):Person(n,"Coach",sl){
	personID = nextID++;
}

int Coach::get_salary()
{
	if(salary <= 0){
		cout << "No negative numbers" << endl;
		salary = 0;
	} else if (salary > 0){
		if(serviceLength <15){
			return salary;
		} else {
			return 3*salary;
		}
	}
}

Coach::~Coach(){

}


