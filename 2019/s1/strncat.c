#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  char firstname[10] = "Brian ";
  char lastname[10] = "Koh";
  char fullname[20] = "";  // initialise with empty string

  strncat(fullname, firstname, 10);
  strncat(fullname, lastname, 10);
  strncat(fullname, firstname, 2);
  strncat(fullname, lastname, 3);

  printf("%s\n", fullname);

  return 0;
    
}
