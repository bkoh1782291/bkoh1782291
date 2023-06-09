#ifndef HUNTER_H
#define HUNTER_H

#include <iostream>
#include <string>
#include "animal.h"

using namespace std;
class hunter: public animal{
private:
	int kills;               // how many kills have been recorded, initialised to 0.
	static int nextID;
public:
	hunter(string n, int v);  // create a hunter with name n and body volume v
	int get_kills();

	string get_name();

	void set_kills(int hKills);


};




#endif