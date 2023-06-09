#include <iostream>
#include <string>
#include "vegie.h"
#include "animal.h"

int main(){
	vegie *v1 = new vegie("carrot", 5);

	v1->set_values("tomato",10);

	cout << "The vegie's ID is :" << v1->get_Id() << endl;
	cout << "The vegie's name is :" << v1->get_name() << endl;
	cout << "The vegie's favourite food is :" << v1->get_favouritefood() << endl;

return 0;

}