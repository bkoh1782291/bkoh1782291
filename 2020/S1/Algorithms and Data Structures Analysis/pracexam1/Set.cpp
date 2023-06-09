#include <iostream>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <cctype>
#include "Set.h"

Set::Set(){

}

int Set::addElement(int n){

	//storing all elements into new array
		newElement[i] = n;
		i++;
		y++;

	return value;
}

int Set::removeElement(){	

	//removing the largest number in the set

	for(i=0; i<y; i++){
		if(newElement[i] == max){
			newElement[i] = newElement[i+1];
			y--;		
		}
	}
	/*
	for(i=0; i<y; i++){
		std::cout << newElement[i] << " ";
	}
	*/

	return *newElement;
}

int Set::findMaximum(){

	for(i=0; i<y; i++){
		if(max < newElement[i]){
			max = newElement[i];
		}
	}

	//std::cout << "largest:" << max << std::endl;

	return max;
}


int Set::returnMaximum(){

	max = 0;

	for(i=0; i<y; i++){
		if(max < newElement[i]){
			max = newElement[i];
		}
	}

	if(y==0){
		return -1;
	}

	return max;
}


double Set::returnAverage(){

	double count = 0;
	for(i=0; i<y; i++){
		sum += newElement[i];
		count++;
	}

	Average = (sum/count);

	if(y==0){
		return -1;
	}

	return Average;
}


int Set::returnMinimum(){

	min = newElement[0];

	for(i=0; i<y; i++){
		if(newElement[i] < max){
			min = newElement[i];
		}
	}
	if(y==0){
		return -1;
	}

	return min;
}


Set::~Set(){

}
