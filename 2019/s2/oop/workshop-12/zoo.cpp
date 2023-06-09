#include <iostream>
#include <string>
#include "animal.h"
#include "hunter.h"
#include "vegie.h"
#include "zoo.h"

using namespace std;

zoo::zoo(string n,int cows,int lions){
	name = n;
	number_of_animals = cows + lions;
	animals = new animal*[number_of_animals];

	for (int i = 0; i < cows; i++)
	{
		vegie *animals_ptr = new vegie("Daisy", 100);
		animals[i] = animals_ptr;
	}
	for (int j = cows; j < lions+cows; j++)
	{
		hunter *animals_ptr = new hunter("Clarence", 50);
		animals[j] = animals_ptr;
	}
	
}

string zoo::get_name(){
	return name;
}

int zoo::get_number_of_animals(){
	return number_of_animals;
}

animal** zoo::get_animals(){
	return animals;
}