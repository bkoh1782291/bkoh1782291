#include <stdio.h>
int main(void) {
    int number;
    int count = 0;
    
    printf("enter a number: ");
    scanf("%d", &number);
    
    if (number == 5) {
        count = 1 ;
    }
    
    printf("%d\n", count);
    return 0;
}
