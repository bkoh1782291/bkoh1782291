#include <stdio.h> 
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int pid;
	const char s[100] = " ";
	const char *params[100];
	int total_commands = 0;
	char line[100];
	char buffer[100];
	int i=0;
	char temp[100][256];
	
	char* status = fgets(line, 100, stdin);

	while (status != NULL ){

	char *token = strtok(line, s);

	char *command = token;

	while (token != NULL){
		//printf("%s\n", token);

		params[total_commands] = token;
		total_commands +=1;
		token = strtok(NULL, s);
	}

	params[total_commands] = NULL;

	printf("base command:%s\n",params[0]);
	printf("parameter 1:%s\n",params[1]);
	printf("parameter 2:%s\n",params[2]);	
	printf("parameter 3:%s\n\n",params[3]);	

	pid = fork();

        if(pid == 0)
        {
            execvp(command, params);
        }

        else{
            wait(NULL);
            printf("complete.\n");
            exit(0);
        }  

    }
     

	return (0);
}