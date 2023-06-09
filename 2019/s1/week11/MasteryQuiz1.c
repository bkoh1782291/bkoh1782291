#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int function(int * b, int c) {
   b++;
   c = 4;

   return c;
}

int main(void) {

   int a = 1;
   int b = 2;
   int c = 3;
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);

   a = function(&b, c);
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
}
    
