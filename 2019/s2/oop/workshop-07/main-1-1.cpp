#include <iostream>
#include <string>
#include "Animal.h"

using namespace std;

int main() {
	Animal* a1;
	Animal* a2;

	a1 = new Animal("Elephant");
	a2 = new Animal("Cheetah");

	a1->set_name("A");
	a2->set_name("B");

	string a1Name = a1->get_name();

	cout << a1Name << endl;

	a1->set_name("C");

	cout << a1->get_name() << endl;


	return 0;
}