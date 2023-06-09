#include <stdio.h>
int main(void){
    float cel; 
    float far;
    printf("enter a temperature value in celcius: ");
    scanf("%f", &cel);
        far = (cel*9)/5 + 32;
    printf("%2.f degrees Celsius is %2.f degrees Farenheit\n", cel, far);
        return 0;
}
