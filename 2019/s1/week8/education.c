#include <stdio.h>
int main(void)
{
    int age; 
    printf("Please enter your age: ");
    scanf("%d", &age);
        if (age >=0 && 7<=7){
    printf("Your age is %d and you have a primary level education.\n", age);
        }
        else if (age >=8 && 12<=12){
    printf("Your age is %d and you have a secondary level education.\n", age);
            }
        else if (age >13){
    printf("Your age is %d and you have a tertiary level education.\n", age);
            }
        return 0;
}
