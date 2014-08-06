#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
	int fd;
	struct sockaddr_in serv_addr;
	struct sockaddr_in cli_addr;
	struct timeval start, stop;
	socklen_t cli_length = sizeof(cli_addr);

	if(argc != 2)
	{
		fprintf(stderr, "%s\n", "Usage: ./tcp_server PORT_NUMBER");
		exit(1);
	}

	if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		fprintf(stderr, "%s\n", "Could not creatr socket.");
		exit(1);
	}

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(atoi(argv[1]));
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	int yes = 1;
	if(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0)
	{
		fprintf(stderr, "%s\n", "Could not set socket options.");
		exit(1);
	}

	if(bind(fd, (struct sockadr*)&serv_addr, sizeof(serv_addr)) < 0)
	{
		fprintf(stderr, "%s\n", "Could not bind socket.");
		exit(1);
	}

	listen(fd, 1);
	fprintf(stderr, "Now listening on TCP port %s.\n", argv[1]);

	int client = accept(fd, (struct sockaddr*)&cli_addr, &cli_length);
	if(client < 0)
	{
		fprintf(stderr, "%s\n", "Error accepting client connection.");
		exit(1);
	}

	fprintf(stderr, "%s\n", "Accepted connection from client!");
	char buf[1024*1024];
	memset(buf, 'A', sizeof(buf));

	int i;
	for(i = 0; i < 10; i++)
	{
		gettimeofday(&start, NULL);
		send(client, buf, sizeof(buf), 0);
		gettimeofday(&stop, NULL);
		double time_sec = ((stop.tv_sec) + (stop.tv_usec / 1000.0 / 1000.0)) - ((start.tv_sec) + (start.tv_usec / 1000.0 / 1000.0));
		double throughput = (sizeof(buf) * 8.0 / 1000.0 / 1000.0) / time_sec;
		fprintf(stderr, "(%d) Throughput: %f Mbps\n", i+1, throughput);
	}

	close(client);
	close(fd);
	return 0;
}
