#define SIGHUP  1   /* Hangup the process */ 
#define SIGINT  2   /* Interrupt the process */ 
#define SIGQUIT 3   /* Quit the process */ 
#define SIGILL  4   /* Illegal instruction. */ 
#define SIGTRAP 5   /* Trace trap. */ 
#define SIGABRT 6   /* Abort. */


// CPP program to illustrate 
// default Signal Handler 
#include<stdio.h> 
#include<signal.h> 

int main() 
{ 
	signal(SIGINT, handle_sigint); 
	while (1) 
	{ 
		printf(“hello world\n”); 
		sleep(1); 
	} 
	return 0; 
} 

