#include <stdlib.h>

int main(void) {
    int count = 0;
    int age;
    char initial;
    char * lastName;
    
    int * agePtr = &age;
    char * initialPtr = &initial;
    int * tempPtr;
    tempPtr = agePtr;
    
    // do we need to free tempPtr before reusing?
    tempPtr = &count;
    tempPtr++;  // what will this do?
    
    // doesnt dynamically hold because number is not initialized
    tempPtr = malloc (number * sizeof(int));
    tempPtr = lastName;
    
    return 0;
}

