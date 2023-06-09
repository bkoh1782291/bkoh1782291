#include <stdio.h>
    int main(void)
{
        int i;
        int length;
        int A[] = {1, 2, 4, 5, 7};
        
    length = sizeof(A)/sizeof(int);
    for (i = length-1; i > -1; i = i-1) {
        if ( A[i] % 2 == 0) { // value mod 2 = 0 indicates even
            return i;
        }  
    }
        printf("%d\n", i);
}
