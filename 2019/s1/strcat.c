#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  char firstname[10] = "Brian ";
  char lastname[10] = "Koh";
  char fullname[20] = "";  // initialise with empty string

  strcat(fullname, firstname);
  strcat(fullname, lastname);

  printf("%s\n", fullname);

  return 0;
}
