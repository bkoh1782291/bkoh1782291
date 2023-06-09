#include <stdio.h>

int main(void) {
    char myString[6];
    int myInt;
    char myChar;
    char nextCharInStream;
    
    printf("Enter a String 5 or fewer characters\n");
    scanf("%5s", myString);
    printf("enter a character\n");
    scanf("%c", &nextCharInStream);
    printf("%c:done\n", nextCharInStream);

    printf("Enter an Integer\n");
    scanf("%d", &myInt);
    scanf("%c", &nextCharInStream);
    printf("%c:done\n", nextCharInStream);
    
    printf("Enter a Character\n");
    scanf("%c", &myChar);
    scanf("%c", &nextCharInStream);
    printf("%c:done\n", nextCharInStream);
    
    // note all of the above leave a \n character in the stream 
    // what is the implication for future scanf calls?
    
    printf("Enter an Integer\n");
    scanf("%d", &myInt);
    printf("Enter a Character\n");
    scanf("%c", &myChar);
    
    printf("myChar contains:%c:done\n", myChar);
    // what character was put in myChar?
    // how could we fix this? how could we match whitespace in our scanf to prevent the newline from being assigned to the character?
    
}
