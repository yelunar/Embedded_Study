#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define IOCTL_TYPE 'I'

#define WRITE_ACT _IOW(IOCTL_TYPE, 1, int*)
#define READ_ACT _IOR(IOCTL_TYPE, 2, int*)
 
void main(int argc, char *argv[])
{
	char req;
        int fd;
        int input;
	int output;
 
        fd = open("/dev/ioctl_test_device", O_RDWR);
        if(fd < 0) {
                printf("Error: canot open device\n");
                return;
        }

	if (argc == 1)
		goto err;

	req = *argv[1];

	if (req == 'R' || req == 'r') {
		goto read;
	} else if (req == 'W' || req == 'w') {
		if (argc != 3) {
			printf("Enter number value\n");
			return;
		}
		input = atoi(argv[2]);
		ioctl(fd, WRITE_ACT, (int*) &input);
		printf("IOCTL write intput: %d\n", input);
		goto read;
	} else {
		printf("Unknown IOCTL request: %s\n", argv[1]);
		goto err;
	}

err:
	printf("Enter IOCTL request ( 'R' or 'W' )\n");
	return;

read:
        ioctl(fd, READ_ACT, (int*) &output);
        printf("IOCTL read output: %d\n", output);

        close(fd);
}
