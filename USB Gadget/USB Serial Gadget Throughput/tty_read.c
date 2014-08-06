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
char buf[1024*1024*10];

int main(int argc, char **argv)
{
	struct timeval start, stop;
	int count = 0;
	int reset = 1;
	int fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_SYNC);
	if(fd < 0)
	{
		perror("open");
		exit(1);
	}

	set_interface_attribs(fd, B115200, 0);
	set_blocking(fd, 1);

	printf("%s\n", "BEGIN");
	while(1)
	{
		//if(reset)
		//{
			gettimeofday(&start, NULL);
			//reset = 0;
		//}
		
		int n = 0;
		while(n < 1024*1024*10)
		{
			 n += read(fd, buf, 1024*1024*10);
		}

		//if(++count > 10)
		//{
			gettimeofday(&stop, NULL);

			double time_sec = ((double)(stop.tv_sec) + (stop.tv_usec / 1000.0 / 1000.0)) - ((double)(start.tv_sec) + (start.tv_usec / 1000.0 / 1000.0));
			double throughput = ((1024*1024*10)*8/1000.0/1000.0) / time_sec;
			fprintf(stderr, "Current Rate: %f Mbps\n", throughput);
			//count = 0;
			//reset = 1;
		//}
	}

	close(fd);
	return 0;
}

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
