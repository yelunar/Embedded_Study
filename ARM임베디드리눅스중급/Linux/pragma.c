#include <stdio.h>

#pragma pack(1)
struct data {
	int key;
	char value;
};

struct data2 {
	int key;
	char value;
};

void main()
{
	printf("data: %d\n", sizeof(struct data));
	printf("data2: %d\n", sizeof(struct data2));

}

