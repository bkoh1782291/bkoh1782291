#include <iostream>
#include <string>
#include "animal.h"
#include "vegie.h"
#include "hunter.h"
#include "zoo.h"

using namespace std;

int main(){

	zoo a = zoo("adelaide zoo", 20,10);

	cout << a.get_number_of_animals()<<endl;

	cout << a.get_animals() << endl;
	return 0;
}