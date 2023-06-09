#include <stdio.h> 
#include <stdlib.h> 
#include <stdint.h>

int main(){
   int abc[4][4];
   int i, j;
   int diag[4];
   for(i=0; i<4; i++) {
      for(j=0;j<4;j++) {
         printf("Enter value for abc[%d][%d]:", i, j);
         scanf("%d", &abc[i][j]);
      }
   }

   for(i=0; i<4; i++) {
      for(j=0;j<4;j++) {
         printf("%d ", abc[i][j]);
         if (j==3){
         	printf("\n");
         }
      }
   }

    for (i=0; i <4; i++){
        diag[i] = abc[i][i];
    }
    
    for (i = 0; i < 4; i++)
        printf("%-5d", diag[i]);
    printf("\n\n");
        
   return 0;
}
