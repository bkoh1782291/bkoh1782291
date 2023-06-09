#include <stdio.h>
#include <string.h>
int main() {
	char buff[100];
	printf("What is the secret?\n");
	fgets(buff, sizeof(buff), stdin);
	strtok(buff, "\n");
	if (strcmp(buff,"xxxx redacted xxxx") == 0) {
		printf("congrats!!\n");
	}
	else {
		printf("sorry, try again :(\n");
	}
}
