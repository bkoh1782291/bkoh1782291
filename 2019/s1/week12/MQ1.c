#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int numbers1[5][4];
    
    int * numbers2 = malloc (5*4*sizeof(int));
    numbers2[2*4+3] = 5;
    
    int ** numbers3 = malloc (5 * sizeof(int *)); 
    for (int r = 0; r < 5; r++) {
        numbers3[r] = malloc(4 * sizeof(int));
    }
    
    printf("%d\n", numbers2[2*4+3]);
  return 0;
}
