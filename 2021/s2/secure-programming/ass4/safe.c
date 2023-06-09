#include "spalloc.c"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

	FILE *file;
	char buf[100];
	/* Intialize random number generator */
	time_t t;
	srand((unsigned) time(&t));

	// get input from textfile
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "\nerror with opening file !\n");
		exit(1);
	}
	else
    {
		// reading input from file
		while( fgets ( buf, 100, file ) != NULL )
        {
            // printf("input from file : %s\n", buf) ;
        }
        fclose(file) ;
    }

	// create two variables for functions like calloc() and realloc()
	// one smaller than the other

	// reading char arr to ascii values
	long int input;
	for(int i = 0; i < strlen(buf); i++)
	{
		input = input + buf[i];
	}

	//create deterministic value between 0-7
	long int hash = (input % 10);
	printf("hash: %d\n", hash);

	// long int small_input = input / (rand() % 123);
	printf("input : %ld\n", input);
	// printf("smaller input : %ld\n", small_input);

	// call sp_seed() and sp_rand()
	// hash a value to make it deterministic, basically mod(%) it by something

	// 111111111111111111111111111111
	// 1111111111110000000000000000000000000000000000



	void *temp;
	void *temp2;
	char *var;
	char *var2;

	// based on input paths, 0 - 7, create input
	switch(hash){
		// case 0:
		// 	break;
		// case 1:
		// 	temp = sp_malloc(input);
		// 	sp_free(temp);

		// 	temp2 = sp_malloc(small_input);
		// 	sp_free(temp2);
		// 	break;
		// case 2:
		// 	temp = sp_calloc(input, sizeof input);
		// 	temp2 = sp_calloc(small_input, sizeof small_input);
		// 	sp_free(temp);
		// 	sp_free(temp2);
		// 	break;
		// case 3:
		// 	temp = sp_malloc(input);
		// 	temp = sp_realloc(temp, sizeof small_input);
		// 	sp_free(temp);
		// 	break;
		// case 4:
		// 	temp = sp_malloc(input);
		// 	temp = sp_realloc(temp, sizeof input);
		// 	sp_free(temp);
		// 	break;
		case 5:
			/* remalloc bug ? testing realloc */
			var = sp_malloc(hash);
			printf("First Array   : ");
			for (int i = 0; i < hash; i++)
			{
				var[i] = 1;
				printf("%d", var[i]);
			}

			var2 = sp_realloc(var, input);
			printf("\nSecond Array  : ");
			for(int i = 0; i < hash; i++)
			{
				printf("%d", var2[i]);
				if (var[i] != var2[i])
				{
					printf("-------------------- ABORT CALL--------------------");
					abort();
				}
			}
			printf("\n\n");
			// temp = sp_calloc(input, sizeof small_input);
			// temp2 = sp_calloc(small_input, sizeof input);
			// sp_free(temp);
			// sp_free(temp2);
			break;
		case 6:
			// max heap bug
			sp_malloc(buf[0]);
			sp_calloc(buf[0], buf[0]);
			break;
		case 7:
			break;
	}


	return 0;
}