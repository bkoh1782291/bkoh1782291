#ifndef COACH_H
#define COACH_H

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

class Coach:public Person
{
private:
	static int nextID;

public:
	Coach();
	Coach(string n, int sl);
	int get_salary();
	~Coach();
};

#endif