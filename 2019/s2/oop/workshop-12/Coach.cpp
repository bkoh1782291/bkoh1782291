#include <iostream>
#include <string>
#include "Coach.h"
#include "Person.h"

using namespace std;

int Coach::nextID = -1;

Coach::Coach():Person("","coach",0)
{
	personID = nextID++;
}

Coach::Coach(string n, int sl):Person(n,"Coach",sl)
{
	personID = nextID++;
}


int Coach::get_salary()
{
	if (serviceLength<15){
		return salary;
	} else {
		return salary*3;
	}
}

Coach::~Coach(){

}






