#include <string>
#include <iostream>
#include "Animal.h"
#include "Bird.h"
#include "SeaCreature.h"

using namespace std;

bool test(string expected, string result) {
   if (result == expected)
        cout << " : PASSED" << endl;
    else
        cout << " : FAILED : expected " << expected << " returned " << result << endl;
}

void test(int expected, int result) {
    if (result == expected)
        cout << " : PASSED" << endl;
    else
        cout << " : FAILED : expected " << expected << " returned " << result << endl;
}

void print(Animal *a) {
    cout << a->toString() << endl;
}
int main() {
    
    string expected;
    string result;

    // testing Animal
    cout << "Testing Animal" << endl;
    Animal myAnimal;
    // testing toString()
    expected = "An animal";
    result = myAnimal.toString();
    test(expected, result);
    
    // testing Bird
    cout << "Testing Bird" << endl;
    Bird myBird;
    // testing toString()
    expected = "A bird";
    result = myBird.toString();
    test(expected, result);
    
    // testing SeaCreature
    cout << "Testing SeaCreature" << endl;
    SeaCreature myOctopus;
    // testing toString()
    expected = "A sea creature";
    result = myOctopus.toString();
    test(expected, result);

    
    // testing print function
    cout << "Testing print()" << endl;
    cout << "Expecting An animal : ";
    print(&myAnimal);
    
    cout << "Expecting A bird : ";
    print(&myBird);
    
    cout << "Expecting A sea creature : ";
    print(&myOctopus);
}
