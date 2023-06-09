#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int id;
	int id2;

	printf("Before Fork\n");
	int i = 0;
	id = fork();
	printf("Fork 1: %d\n", id);
	if (id == 0)
	{
		printf("Child\n");
		id2 = fork();
		printf("Fork 2: %d\n", id2);
		if (id2 > 0)
		{
			printf("Child is now a Parent\n");
			wait(NULL);
		}
		else if  (id2 == 0)
		{
			printf("Grandchild I guess?\n");
		}
		return 0;
	}
	else if (id > 0)
	{
		printf("Parent\n");
		wait(NULL);
	}
}
