#include <stdio.h>

void add_int(int *pa, int *pb, unsigned int n, int x)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		pa[i] = pb[i] + x;
}

void main()
{
	int a[] = {11,22,33,44,55,66,77,88,99};
	int b[] = {1,2,3,4,5,6,7,8,9};
	unsigned int i;

	add_int(a, b, 9, 2);

	for (i = 0; i < 9; i++)
		printf("%d,", a[i]);
	printf("\n");
}

