#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
  char firstname[5];
  char lastname[5];
  char fullname[20] = "";  // initialise with empty string

  int count = scanf("%s %s", firstname, lastname);

  strcat(fullname, firstname);
  strcat(fullname, lastname);
  
  printf("%s\n", fullname);
    int leng = strlen(fullname);
    printf("%d", leng);
  return 0;

}
