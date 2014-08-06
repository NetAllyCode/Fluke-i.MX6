#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	struct sockaddr_in sock;
	struct addrinfo ip, *ip_ptr;
	char buf[1024*1024];
	
	if(argc != 3)
	{
		fprintf(stderr, "%s\n", "Usage: ./tcp_client SERVER PORT");
		exit(1);
	}
	
	memset(&sock, 0, sizeof(sock));
	memset(&ip, 0, sizeof(ip));
	ip.ai_socktype = SOCK_STREAM;
	ip.ai_family = AF_INET;

	if(getaddrinfo(argv[1], argv[2], &ip, &ip_ptr) != 0)
	{
		fprintf(stderr, "%s\n", "Could not get addrinfo.");
		exit(1);
	}

	fd = socket(ip_ptr->ai_family, ip_ptr->ai_socktype, ip_ptr->ai_protocol);
	if(fd < 0)
	{
		fprintf(stderr, "%s\n", "Error creating socket.");
		exit(1);
	}

	if(connect(fd, ip_ptr->ai_addr, ip_ptr->ai_addrlen) < 0)
	{
		fprintf(stderr, "%s\n", "Error connecting to server.");
		exit(1);
	}

	int i;
	for(i = 0; i < 10; i++)
	{
		int len = read(fd, buf, sizeof(buf));
		fprintf(stderr, "%s", ".");
		sleep(1);
	}
	
	fprintf(stderr, "%s\n", "");
	close(fd);

	return 0;
}
