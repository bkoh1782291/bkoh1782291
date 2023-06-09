#ifndef MEERKAT_H
#define MEERKAT_H

#include <iostream>
#include <string>

using namespace std;

class meerkat
{
public:
	string name;
	int age;

	meerkat();
	void setName(string meerName);
	string getName();
	void setAge(int meerAge);
	int getAge();
};

#endif //MEERKAT_H