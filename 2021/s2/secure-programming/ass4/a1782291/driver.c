#include <stddef.h>
#include "spalloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(int argc, char *argv[]){

    FILE * file;
	int hash;
	int input = 0;
	int small_input = 0;
	int large_input = 0;
    char buffer[1000];

	/* reading in AFL test files */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "\nerror with opening file !\n");
		exit(1);
	}
	else {
		while(!feof(file))
		{
			fgets(buffer, 1000, file);
		}
		fclose(file);
	}

    printf("\n\nString: %s\n", buffer);

    // calculate the sum of the string's ascii value
    for (int i = 0; i < strlen(buffer); ++i)
    {
        input += buffer[i];
    }
	printf("buffer combined ASCII value : %d\n", input);

	// creating hash {0...14}
    hash = input % 14;
	small_input = hash *2;

    printf("hash value: %d\n\n", hash);

	// BUG 1 Heap Overflow : allocate malloc and calloc with huge sizes and compare to DSP fake
	// BUG 2 sp_realloc error : reallocation of memory fails, comparing first malloc array and second malloc array
    // BUG 3 sp_free error : calling sp_free() many times will cause a crash

	char *var1;
    char *var2;
	large_input = input * 1234;

	/*  simulating paths with hashed value  */
    switch(hash){
        case 0:
			printf("----------------------------- case 0 --------------------------------\n");

			var1 = sp_malloc(large_input);
            var1 = sp_calloc(large_input, input);
			printf("case 0 var 1 : %s \n", var1);
			printf("case 0 var 2 : %s \n", var2);
            // sp_free(singleLine[0]);
            break;
		case 1:
			printf("\n----------------------------- case 1 --------------------------------\n");

			var1 = sp_malloc(input);
			var2 = sp_malloc(small_input);

			break;
		case 2:
			printf("\n----------------------------- case 2 --------------------------------\n");

			var1 = sp_calloc(input, sizeof input);
			var2 = sp_calloc(small_input, sizeof small_input);
			break;
		case 3:
			printf("\n----------------------------- case 3 --------------------------------\n");

			var1 = sp_malloc(input);
			var2 = sp_realloc(var1, sizeof small_input);
			break;
		case 4:
			printf("\n----------------------------- case 4 --------------------------------\n");

			var1 = sp_malloc(input);
			printf("array 1: \n");
            for (int i = 0; i < hash; i++)
            {
                var1[i] = 1;
                printf("%d", var1[i]);
            }
			var2 = sp_realloc(var1, sizeof input);
			sp_free(var1);
			printf("array 2: \n");
            for (int i = 0; i < hash; i++)
            {
                printf("%d", var2[i]);
				printf("\n-------------------- waiting for assert() call ---------------------- \n\n");
				assert(var1[i] != var2[i]);
            }
			break;

         case 5:
			printf("\n----------------------------- case 5 --------------------------------\n");

            var1 = sp_malloc(hash);
            printf("array 1: \n");
            for (int i = 0; i < hash; i++)
            {
                var1[i] = 1;
                printf("%d", var1[i]);
            }

            printf("\n");

            var2 = sp_realloc(var1, input);
			printf("array 2: \n");
            for (int i = 0; i < hash; i++)
            {
                printf("%d", var2[i]);
				printf("\n-------------------- waiting for assert() call ---------------------- \n\n");
				if (var1[i] != var2[i]) abort();
            }

			// for (int i = 0; i < hash; i++)
            // {
			// 	assert(var1[i] != var2[i]);
			// }

			break;
		case 6:
			printf("\n----------------------------- case 6 --------------------------------\n");
			var1 = sp_malloc(large_input);
			sp_free(var1);
			sp_free(var1);
			sp_free(var1);
			sp_free(var1);
			sp_free(var1);
			var1 = sp_realloc(var1, input);
			break;

		case 7:
			printf("\n----------------------------- case 7 --------------------------------\n");
			var1 = sp_malloc(large_input);
			for (int i = 0; i < input; i++)
			{
				var1[i] = 1;
				printf("%d", var1[i]);
			}
			printf("\n\n");
			var2 = sp_calloc(input, input);
			for (int i = 0; i < input; i++)
			{
				printf("%d", var2[i]);
			}
			printf("\n\n");
			break;
		case 8:
			printf("\n----------------------------- case 8 --------------------------------\n");

			var1 = sp_malloc(input);
			var1 = sp_malloc(input);
			var1 = sp_malloc(input);
			var1 = sp_malloc(input);
			break;
		case 9:
			printf("\n----------------------------- case 9 --------------------------------\n");

			var1 = sp_malloc(input);
			var1 = sp_realloc(input, input);
			var1 = sp_realloc(input, input);
			var1 = sp_realloc(input, input);
			break;
		case 10:
			printf("\n----------------------------- case 10 --------------------------------\n");

			var1 = sp_calloc(input, input);
			var2 = sp_calloc(small_input, input);
			break;
		case 11:
			printf("\n----------------------------- case 12 --------------------------------\n");

			var1 = sp_malloc(input);
			sp_free(var2);
			var2 = sp_malloc(small_input);
			sp_free(var1);
			break;
		case 12:
			printf("\n----------------------------- case 13 --------------------------------\n");

			var1 = sp_malloc(input);
			var2 = sp_malloc(small_input);

			break;
	}
    return 0;
}