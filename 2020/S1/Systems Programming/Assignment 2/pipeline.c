#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	char buffer[100];
    int i = 0;
    int total_commands = 0;
    int pid;

    const char *params[100];
    char *command;
    char temp[100][100];

	int pipe1[2];
	int pipe2[2];

	pid_t my_pid;

	if (pipe(pipe1) == -1)
	{
		printf("Error, Pipe 1 Failed\n");
		return 1;
	}
	if (pipe(pipe2) == -1)
	{
		printf("Error, Pipe 2 Failed\n");
		return 1;
	}

	while (fgets(buffer, sizeof buffer, stdin)) 
    {
        printf("%s", buffer);
        
        strcpy(temp[i],buffer);
        i++;

    }

    my_pid = fork();

    //fork failed vibe check
    if (my_pid < 0)
	{
		printf("Failed Fork\n");	
	}

	//parent forked
	else if (my_pid > 0)
	{

		printf("\n");
    	
	}
	
	return 0;
}




