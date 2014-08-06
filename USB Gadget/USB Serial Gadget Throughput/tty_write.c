#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

int set_interface_attribs(int fd, int speed, int parity);
void set_blocking(int fd, int block);
//void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

char pktbuf[1024*1024*10];
int fd;

int main(int argc, char **argv)
{
	fd = open("/dev/ttyGS0", O_RDWR | O_NOCTTY | O_SYNC);
	if(fd < 0)
	{
		perror("open");
		exit(1);
	}

	set_interface_attribs(fd, B115200, 0);
	set_blocking(fd, 0);
	
	/*pcap_t *handle;
	char errbuf[PCAP_ERRBUF_SIZE];
	char *dev = "eth0";
	
	handle = pcap_open_live(dev, 64, 1, 500, errbuf);
	if(handle == NULL)
	{
		perror("pcap_open_live");
		exit(1);
	}

	fprintf(stderr, "%s\n", "Enter capture loop...");
	pcap_loop(handle, -1, handle_packet, NULL);

	close(fd);*/

	int i;
	for(i = 0; i < 1024*1024*10; i++)
	{
		pktbuf[i] = 'A';
	}

	printf("%s\n", "Finished prepping buf");

	while(1)
	{
		write(fd, pktbuf, 1024*1024*10);
	}

	close(fd);
	return 0;
}

/*void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
	memcpy(pktbuf, packet, 64);
	write(fd, packet, 64);
}*/

int set_interface_attribs(int fd, int speed, int parity)
{
	struct termios tty;
	memset(&tty, 0, sizeof(tty));
	if(tcgetattr(fd, &tty) != 0)
	{
		perror("tcgetattr");
		exit(1);
	}

	cfsetospeed(&tty, speed);
	cfsetispeed(&tty, speed);

	tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;
	tty.c_iflag &= ~IGNBRK;
	tty.c_lflag = 0;
	tty.c_oflag = 0;
	tty.c_cc[VMIN] = 0;
	tty.c_cc[VTIME] = 5;

	tty.c_iflag &= ~(IXON | IXOFF | IXANY);
	tty.c_cflag |= (CLOCAL | CREAD);
	tty.c_cflag &= ~(PARENB | PARODD);
	tty.c_cflag |= parity;
	tty.c_cflag &= ~CSTOPB;
	tty.c_cflag &= ~CRTSCTS;

	if(tcsetattr(fd, TCSANOW, &tty) != 0)
	{
		perror("tcsetattr");
		exit(1);
	}

	return 0;
}

void set_blocking(int fd, int block)
{
	struct termios tty;
	memset(&tty, 0, sizeof(tty));
	
	if(tcgetattr(fd, &tty) != 0)
	{
		perror("tcgetattr");
		exit(1);
	}

	tty.c_cc[VMIN] = block ? 1:0;
	tty.c_cc[VTIME] = 5;

	if(tcsetattr(fd, TCSANOW, &tty) != 0)
	{
		perror("tcsetattr");
		exit(1);
	}
}
