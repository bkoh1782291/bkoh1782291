#include <iostream>
#include <string>
#include "meerkat.h"

using namespace std;

meerkat::meerkat()
{
}

void meerkat::setName(string meerName)   // change the meerkat's name
{
	name = meerName;
}

string meerkat::getName()
{
	return name;
}

void meerkat::setAge(int meerAge)        // change the meerkat's age
{
	age = meerAge;
}

int meerkat::getAge()
{
	return age;
}


