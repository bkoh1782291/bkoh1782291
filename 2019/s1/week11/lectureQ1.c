#include <stdio.h>
int main()
{
    int array[] = {1,2,3,4,5,6};
    int *ptr = array;
    printf("%ld\n", sizeof(ptr));
    printf("%d\n", ptr[2]);
    return 0;
}
