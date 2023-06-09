#include <iostream>
using namespace std;

int main (void) {
    char s1[] = "abc";
    
    // char *s2 = "def"; 
    // breaks standards!!
    // correct way
    char s[] = "def";
    char * s2 = s;

    char *p1 = s1;

    // section 1
    cout << "*p1  " << *p1 <<endl;
    s1[0] = 'z';
    cout << "New *p1  " << *p1 <<endl;

    // section 2
    s2 +=1; 
    cout << "New *s2  " << *s2 <<endl;

    // section 3
    p1 +=1; 
    cout << "New *p1  " << *p1 <<endl; 
}