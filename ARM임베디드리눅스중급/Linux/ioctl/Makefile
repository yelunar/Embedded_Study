obj-m += ioctl_driver.o

KDIR = /lib/modules/$(shell uname -r)/build

all:
	make -C $(KDIR)  M=$(shell pwd) modules
	gcc -o ioctl_user ioctl_user.c
clean:
	make -C $(KDIR)  M=$(shell pwd) clean
	rm ioctl_user

