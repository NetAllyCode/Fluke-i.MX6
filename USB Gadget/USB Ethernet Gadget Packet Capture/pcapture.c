#include <pcap.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include "ethernet.h"

void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

typedef struct packed_int
{
	unsigned char b1;
	unsigned char b2;
	unsigned char b3;
	unsigned char b4;
} packed_int;

typedef union
{
	unsigned int i;
	packed_int b;
} packed;

int client;
char pktbuf[100];

int main(int argc, char **argv)
{
	//SOCKET STUFF
	int fd;
	struct sockaddr_in sock, cli_sock;
	socklen_t client_length = sizeof(client);

	if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket");
		exit(1);
	}
	memset(&sock, 0, sizeof(sock));
	sock.sin_family = AF_INET;
	sock.sin_port = htons(8999);
	sock.sin_addr.s_addr = ntohl(INADDR_ANY);
	
	int yes = 1;
	if(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0)
	{
		perror("setsockopt");
		exit(1);
	}

	if(bind(fd, (struct sockaddr*)&sock, sizeof(sock)) < 0)
	{
		perror("bind");
		exit(1);
	}

	listen(fd, 1);
	fprintf(stderr, "%s\n", "Now listening on TCP port 8999.");
	
	client = accept(fd, (struct sockaddr*)&cli_sock, &client_length);
	if(client < 0)
	{
		perror("accept");
		exit(1);
	}

	//PCAP STUFF
	pcap_t *handle;
	char errbuf[PCAP_ERRBUF_SIZE];
	char *pkt;
	char *dev = "eth0";
	struct pcap_pkthdr header;

	handle = pcap_open_live(dev, 64, 1, 500, errbuf);
	
	if(handle == NULL)
	{
		perror("pcap_open_live");
		exit(1);
	}
	
	pcap_loop(handle, -1, handle_packet, NULL);

	return 0;
}

void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
	memcpy(pktbuf, packet, 64); //Strip packet to 64 bytes and send
	send(client, pktbuf, 64, 0);

}
