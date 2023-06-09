#ifndef SET_H
#define SET_H

#include <iostream>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <cctype>

class Set{
public:

	Set();

	//adds an integer n to the set if it is not already contained in the set.
	int addElement(int n);

	int findMaximum();

	//removes the integer n if it is already contained in the set.
	int removeElement();

	//returns a double giving the average value of the elements in the set.
	double returnAverage();

	// returns an integer giving the maximum value among all elements in the set.
	int returnMaximum();

	//returns an integer giving the minimum value among all elements in the set.
	int returnMinimum();

	~Set();

private:
	
	int *newElement = new int[10];
	int value;
	int i = 0;
	int y = 0;

	double Average;
	int sum;
	int max;
	int min;

};

#endif