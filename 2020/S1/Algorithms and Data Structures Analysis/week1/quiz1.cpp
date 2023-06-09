#include <iostream>
using namespace std;

int main(){

    int x, *xp;
   double y, *yp;
   char z, *zp;

   // this creates a class type, it's a shortcut just to get a basic class
   // c is declared to be a variable that is this class type.
   // *cp is a pointer to an object of this class
   class {
        int temp[1000];
    } c, *cp;

    // print the sizes in bytes of the variables
    cout<<" "<<endl;
    cout<<sizeof(x)<<endl;
    cout<<sizeof(y)<<endl;
    cout<<sizeof(z)<<endl;
    cout<<sizeof(c)<<endl;

    // print the sizes of the pointer variables
    cout<<" "<<endl;
    cout<<sizeof(xp)<<endl;
    cout<<sizeof(yp)<<endl;
    cout<<sizeof(zp)<<endl;
    cout<<sizeof(cp)<<endl;

    // print the sizes of what the pointers point to
    cout<<" "<<endl;
    cout<<sizeof(*xp)<<endl;
    cout<<sizeof(*yp)<<endl;
    cout<<sizeof(*zp)<<endl;
    cout<<sizeof(*cp)<<endl;

    return 0;
}
