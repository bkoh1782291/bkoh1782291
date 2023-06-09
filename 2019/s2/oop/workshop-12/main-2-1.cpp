#include <iostream>
#include <string>
#include "hunter.h"
#include "animal.h"

int main(){
	hunter *h1 = new hunter("joe", 5);

	h1->set_values("brian",10);

	cout << "The hunter's ID is :" << h1->get_Id() << endl;
	cout << "The hunter's name is :" << h1->get_name() << endl;
	cout << "The hunter's kill count is :" << h1->get_noOfKills() << endl;


}