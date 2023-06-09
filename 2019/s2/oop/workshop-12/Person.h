#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person{
protected:
	string name;
	string occupation;
	int salary;
	int serviceLength;
	int personID;
	int id;
public:
	Person(string n, string o, int sl);
	//getters
	string get_name();
	string get_occupation();
	virtual int get_salary() = 0;
	int get_serviceLength();
	int get_personID();
	//setters
	void set_name(string aName);
	void set_occupation(string aOccupation);
	void set_salary(int aSalary);
	void set_personID(int aPersonID);

	virtual ~Person();

};

#endif

