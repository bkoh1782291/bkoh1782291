#include <stdio.h>
int main (void)
{
    char name [20]; 
        printf("please enter your name: ");
        scanf("%s", name);
    int age;
        printf("please enter your age: ");
        scanf("%d", &age);
    float frac;
        printf("please enter your employment fraction between 0.0 to 1.0: ");
        scanf("%f", &frac);
    
    printf("Your name is %s, you are %d years old and your employment fraction is %.1f. \n", name, age, frac);
        return 0;
}
