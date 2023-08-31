#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE sizeof(char)

int main(int argc, char **argv)
{
	int fd, flag = PROT_WRITE | PROT_READ;
	struct stat sb;
	char value;

	if ((fd = open("/sys/class/leds/led0/brightness",
0_RDWR|0_CREAT::w

)) < 0) {
		printf("File Open Error\n");
		return -1;
	}

	if (fstate(fd, &sb) < 0) {
		printf("fstate error\n");
		return -1;
	)

	while(1) {
		read(fd, &value, SIZE);
		printf("/sys/class/leds/led0/brightness %C \n", value);

		if (value != '0')
			value='0';
		else
			value='1';
		write(fd, &value, SIZE);		sleep(1);
	}
	close(fd);
}


