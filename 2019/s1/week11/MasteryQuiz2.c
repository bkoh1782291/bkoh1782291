#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Q1
int main(){
   int count = 1;
   int number;
   int * ptr = &count;
   int * ptr2 = &number;
    printf("%ld\n", sizeof(count));
      printf("%ld\n", sizeof(number));
    printf("%ld\n", sizeof(*ptr));
      printf("%ld\n", sizeof(*ptr2));
    printf("\n");
       printf("%d\n", count);
        printf("%d\n", number);

    printf("value 1: %d\n", *ptr);
        printf("value 2: %d\n", *ptr2);

   // Q2
   ptr = ptr2;
   *ptr2 = 3;


   // Q3
   ptr = malloc (number * sizeof(char));
     printf("%ld\n", (number * sizeof(char)));
      printf("%ld\n", (count * sizeof(char)));
    
   // Q4
   ptr2 = malloc (count * sizeof(char));
   ptr = ptr2;
       printf("ptr 1: %d\n", *ptr);
        printf("ptr 2: %d\n", *ptr2);
 
}
