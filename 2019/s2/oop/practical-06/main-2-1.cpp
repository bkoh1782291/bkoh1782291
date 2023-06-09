#include <iostream>
#include <string>
#include "cart.h"
#include "meerkat.h"

using namespace std;

int main(){

	meerkat v[5];

 	string name[5] = {"a","b","c","d","e"};
 	int age[5] = {2,4,5,6,7};

 	/*for (int i = 0; i < 5; i++){
 		meerkat meerk[i] = meerkat();
 	}*/

	meerkat meerkat1 = meerkat();
	meerkat meerkat2 = meerkat();
	meerkat meerkat3 = meerkat();
	meerkat meerkat4 = meerkat();
	meerkat meerkat5 = meerkat();

	cart *meers = new cart();

	for(int i = 0; i < 5; i++){
		v[i].setName(name[i]);
		v[i].setAge(age[i]);
	}

	if(meers->addMeerkat(meerkat1)!=false){
		cout << "The cart stll has space " << endl;
	} else if (meers->addMeerkat(meerkat1)==false){
		cout << "The cart is full when meerkat1" << " enters ! " << endl;
	}
	

	meers->printMeerkats();
	cout << endl;
	meers->emptyCart();

	return 0;
}