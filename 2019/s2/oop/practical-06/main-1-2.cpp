#include <iostream>
#include <string>
#include "person.h"

using namespace std;

int main()
{
	person *a = new person("brian", 2000);
 	person *b = new person("jack", 2600);
 	person *c = new person("eric", 4000);
 	person *d = new person("steve", 6000);
 	
 	cout << "\n";
 	cout << a->getName() << endl;
 	cout << a->getSalary() << endl;
 	 	cout << "\n";

 	cout << b->getName() << endl;
 	cout << b->getSalary() << endl;
 	 	cout << "\n";

 	cout << c->getName() << endl;
 	cout << c->getSalary() << endl;
 	 	cout << "\n";

 	cout << d->getName() << endl;
 	cout << d->getSalary() << endl;
 	 	cout << "\n";

 	delete a;
 	delete b;
 	delete c;
 	delete d;

 	return 0;
	
}

/*person v[4];

 	string name[4] = {"brian", "eric", "steve", "johnny"};
 	int Salary[4] = {2000,4000,5000,6000};

 	cout << "names of person and Salary are " << endl;

 	for(int i =0; i<4;i++){
 		v[i].setName(name[i]);
 		v[i].setSalary(Salary[i]);
 		cout << v[i].getName() << " ";
 		cout << v[i].getSalary() << " ";
 	}

 	cout << "\n" << endl;
	
	return 0;
 */
