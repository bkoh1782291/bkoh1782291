#ifndef SORTPERSON_H
#define SORTPERSON_H

#include "SortPerson.h"
#include "Person.h"
#include "Team.h"
#include "Coach.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

class SortPerson
{
public:
	static void sort(Person **people, int n);
};

#endif
