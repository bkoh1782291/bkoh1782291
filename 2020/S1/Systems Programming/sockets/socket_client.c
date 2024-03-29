#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define PORTNUM 13000
#define HOSTLEN 256

int main(int argc, char **argv)
{
	struct sockaddr_in servadd;
	struct hostent     * hp;
	int    sock_id, sock_fd;
	char   message[BUFSIZ];
	int    messlen;

	// ##################################################
	// ## PART 1: Get a socket

	sock_id = socket( AF_INET, SOCK_STREAM, 0);
	if (sock_id == -1)
	{
		perror("Client Socket Error");
		return 1;
	}
	
	// ##################################################
	// ## PART 2: Connect to server

	// Zero the address
	bzero(&servadd, sizeof(servadd));

	hp = gethostbyname(argv[1]);
	if (hp == NULL)
	{
		perror(argv[1]);
		return 1;
	}

	bcopy(hp->h_addr, (struct sockaddr *) &servadd.sin_addr, hp->h_length);

	servadd.sin_port = htons(atoi(argv[2]));
	servadd.sin_family = AF_INET;

	// Dial
	if (connect(sock_id, (struct sockaddr *) &servadd, sizeof(servadd)) != 0)
	{
		perror("Client Connect Error\n");
		return 1;
	}

	// ##################################################
	// ## PART 3: The substance

	messlen = read(sock_id, message, BUFSIZ);
	if (messlen == -1)
	{
		perror("Client Read Error\n");
		return 1;
	}
	if (write(1, message, messlen) != messlen)
	{
		perror("Client Write Error\n");
		return 1;
	}
	close(sock_id);

	return 0;	
}

