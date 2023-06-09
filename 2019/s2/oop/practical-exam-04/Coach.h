#ifndef COACH_H
#define	COACH_H

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

class Coach: public Person{
protected:
	static int nextID;
public:
	Coach();
	Coach(string n, int sl);

	//getters
	int get_salary();

	~Coach();
};

#endif