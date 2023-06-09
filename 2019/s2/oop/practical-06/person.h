#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class person
{
public:
	int salary;
	string name;

	person(string myName, int Salary);
	void setName(string myName);
	string getName();
	void setSalary(int mySalary);
	int getSalary();
};

#endif //PERSON_H