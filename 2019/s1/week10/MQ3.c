#include <stdio.h>
#include <stdlib.h>
int main(void){
     int number;
    int *n = &number;  // replace this with initialisation code
    scanf("%d", n);
    printf("%d", number);
    return 0;
}
