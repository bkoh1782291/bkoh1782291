#ifndef PERSON_H
#define	PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
	string name;                   
	string occupation;                
	int salary;                        
	int serviceLength;                   
	int personID;
	int id;
	int s;                    
public:
	Person();
	Person(string n, string o, int sl);

	// getters
	virtual int get_salary() = 0;
	string get_name();
	string get_occupation();
	int get_personID();

	//setters
	void set_name(string aName);
	void set_occupation(string aOccupation);
	void set_salary(int aSalary);

	virtual ~Person();
};


#endif