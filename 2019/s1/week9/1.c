#include <stdio.h>
    int main(void)
    {
        int array[12];
        int i;
        int num;

        printf("Enter the size of an array \n");
        scanf("%d", &num);
        printf("Enter the elements of the array \n");
 
        for (i = 0; i < num; i++) 
        {
            scanf("%d", &array[i]);
        }
 
        printf("Even numbers in the array are: ");
        for (i = 2; i < 11; i = i+2) 
        {
                printf("%d \t", i);
        }
    }
        
