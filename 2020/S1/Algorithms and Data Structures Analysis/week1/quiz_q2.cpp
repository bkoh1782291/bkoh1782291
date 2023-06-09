#include <iostream>
using namespace std;

int main (void) {
    int p;
    double d; 
    int *xp = &p;
    double *yp= &d;

    class {
        int temp[1000];
    } c1, *cp=&c1;

    cout << "xp:  " << xp << endl;
    cout << "xp+1:  " << xp+1<< endl;

    cout << "yp:  " << yp << endl;
    cout<< "yp+1:  " << yp+1 << endl;

    cout << "cp:  " << cp << endl;
    cout << "cp+1:  " << cp+1<< endl;
    
}