#include <iostream>
#include <string>
#include "animal.h"
#include "newAnimal.h"

using namespace std;

int main(){

  newAnimal *animalA = new newAnimal();
  animalA->set_values("dog",10);
  cout << "The animal's ID is :" << animalA->get_AnimalId() << endl;
  cout << "The animal's name is: " << animalA->get_name() << endl;
  cout << "The animal's volume is: " << animalA->get_volume() << endl;

	return 0;
}