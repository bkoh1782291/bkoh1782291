#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *src = "hello"; 
    char *new_string = malloc(strlen(src)+1  * sizeof(char));
        if (new_string == NULL)
        {
            return 1;
        }
    for(int i=0; i < strlen(src)+1; i++) {
        new_string[i] = src[i];
    }
    printf("%s\n", new_string);
        free(new_string);
        return 0;
}
