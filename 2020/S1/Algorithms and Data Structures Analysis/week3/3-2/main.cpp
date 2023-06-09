#include <iostream>
#include "Animal.h"
#include "Bird.h"
#include "SeaCreature.h"

using namespace std;

void print(Animal *a) {
    cout << a->toString() << endl;
}
int main() {
    Animal myAnimal;
    Bird myBird;
    SeaCreature myOctopus;
    
    cout << endl << myAnimal.toString() << endl;
    cout << myBird.toString() << endl;
    cout << myOctopus.toString() << endl << endl;

    print(&myAnimal);
    print(&myBird);
    print(&myOctopus);
}
