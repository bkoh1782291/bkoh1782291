#include <stdio.h> 
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>

/*
while (TRUE)
{
    read_command(command, params);
    pid= fork();

    if (pid < 0) // fork failed
    {
        handle_error();
    } 
    else if //parent process, waits for child to finish
    {
        wait(NULL);
    } 
    else // child process, executes command and finishes
    {
        execvp(command, params);
    }
}

printf("Type something\n");
scanf("%s", input_str);


int main(void)
{
    char buffer[100];
    int i = 0;
    int j=0;
    char *token;
    const char s[100] = " ";
    char temp[100][256];

    while (fgets(buffer, sizeof buffer, stdin)) 
    {
        //printf("%s", buffer);
        
        strcpy(temp[i],buffer);
        i++;

    } 

    for (j=0; j<i; j++){
        printf("%s", temp[j]);
    }
*/


int main(void)
{
    char buffer[100];
    int i = 0;
    int total_commands = 0;
    int pid;
    int j;

    const char *params[100];
    char *command;
    char temp[100][100];
    //int x=0;

    while (fgets(buffer, sizeof buffer, stdin)) 
    {
        //printf("%s", buffer);
        
        strcpy(temp[i],buffer);
        i++;

        char *token = strtok(buffer, " ");

        command = token;

        while (token != NULL){
        
        //printf("%s\n", token);

            params[total_commands] = token;
            total_commands +=1;
            token = strtok(NULL, " ");

        }

        params[total_commands] = NULL;

        /*
        pid = fork();

 
        if(pid == 0)
        {
            execvp(command, params);
        }

        else{
            wait(NULL);
            //printf("complete.\n");
            exit(1);
        }
        */

    } 
        
	/*	
    for(j=0; j<i; j++){
        system(temp[j]);
    }
    
    for (int i=0; i<4; i++){
    //}

        int total_commands = 0;

        token = strtok(buffer, delim);

        char *command = token;

        printf("token:%s\n", token);
    */

    for (j=0; j<i; j++){
        system(temp[j]);
    }

    return 0;
}