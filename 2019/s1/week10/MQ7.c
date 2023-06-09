#include <stdio.h>
int main(void) {
  char firstname[6];
  char lastname[6];
  int favouriteNumber;

  int returnValue = scanf("%s %s %d", firstname, lastname, &favouriteNumber);
    printf("%d", returnValue);
}
