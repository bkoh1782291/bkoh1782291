#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Musician.h"
#include "Orchestra.h"

using namespace std;

int main(){
	
	int size = 0;
	int i;

	Orchestra *v1;

	v1 = new Orchestra(0);

	int current_members = v1->get_current_number_of_members();
	char instrument_check = v1->has_instrument("double bass");
	Musician *all_members = v1->get_members();
	bool full_check = v1->add_musician(Musician());

	for(i = 0; i<10; i++){
		cout << "my orchestra currently has " << v1[i].get_current_number_of_members() << " members" << endl;
	}

	for(i = 0; i<10; i++){
		cout << "my orchestra does have a " << v1[i].has_instrument("double bass") << endl;
	}	

	cout << "the members of my orchestra is :" << endl;
	for(i = 0; i<10; i++){
		cout << v1[i].get_members() << endl;
	}

	return 0;








































}
