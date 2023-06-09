#include <iostream>
#include <string>
#include "cart.h"
#include "meerkat.h"

using namespace std;

int i;

cart::cart(){                       // create an empty cart object
	for(i=0; i<5; i++){
		age[i] = 0;
		names[i] = "?";
	}
	count = 0;
}

bool cart::addMeerkat(meerkat cat){   // adds a meerkat to the cart, returns false if full
	
	bool check = true;

	if(count==4){
		check = false;
	}
	else{
		age[count]=cat.getAge();
		names[count]=cat.getName();
		count++;
	}

	return check;
}

void cart::emptyCart(){          // remove all meerkats from the cart
	for (i = 0; i < 5; i++){
		age[i] = 0;
		names[i] = "?";
	}
	count = 0;
}


void cart::printMeerkats(){      // print the name, a space, the age, then a new line
                             	// for each meerkat in the order they were added
	for (i = 0; i < 5; i++){
		cout << names[i] << " " << age[i] << endl; 
	}

}