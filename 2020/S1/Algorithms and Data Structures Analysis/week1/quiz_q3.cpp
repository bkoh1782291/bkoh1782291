#include <iostream>
using namespace std;

int main (void) {

    int a[3] = {2012, 2, 14};
    int* p1 = &a[0];
    int* p2 = a;

    cout <<"a: " << a<< endl;
    cout <<"a+1: " << a+1<< endl;

    // section 2
    cout <<"*(a+2): " << *(a+2)<< endl;
    *(a+2) = 3;
    cout <<"New *(a+2): " << *(a+2)<< endl;

    // section 3
    cout <<"*(a+3): " << *(a+3)<< endl;
    *(a+3) = 0xbfff37c;

}