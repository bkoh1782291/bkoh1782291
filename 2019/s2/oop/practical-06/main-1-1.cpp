#include <iostream>
#include <string>
#include "meerkat.h"

using namespace std;

int main(){

 	meerkat v[4];

 	string name[4] = {"a","b","c","d"};
 	int age[4] = {2,4,5,6};

 	cout << "names and ages of the meerkats are" << endl;

 	for(int i =0; i<4;i++){
 		v[i].setName(name[i]);
 		v[i].setAge(age[i]);
 		cout << v[i].getName() << " ";
 		cout << v[i].getAge() << " ";
 	}

 	cout << "\n" << endl;
	
	return 0;
}

//for (int i = 0; i < 4; i++){
	//	meerkat *[i];
	//}

	/*meerkat *first = new meerkat("A");
	meerkat *second = new meerkat();
	meerkat *third = new meerkat();
	meerkat *forth = new meerkat();

	first->setName("a");
	first->setAge(5);

	second->setName("b");
	second->setAge(4);

	third->setName("c");
	third->setAge(3);

	forth->setName("d");
	forth->setAge(2);

	delete first;
	delete second;
	delete third;
	delete forth;
 	*/