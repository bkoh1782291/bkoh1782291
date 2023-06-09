#include <iostream>
#include <string>
#include "newAnimal.h"
#include "animal.h"

using namespace std;

newAnimal::newAnimal(){

}

string newAnimal::get_name()
{
  return name;
}

int newAnimal::get_volume(){
  return volume;
}

int newAnimal::get_AnimalId(){
  id++;
  return id;
}

newAnimal::~newAnimal(){

}