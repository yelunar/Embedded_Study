#include <stdio.h>
#include <stdlib.h>

void main()
{
	char a = 'a';
	char *stack_addr;
	int *heap_addr;

	stack_addr = &a;
	heap_addr = malloc(sizeof(int));
	*heap_addr = 10;

	printf("stack addr: %p\n", stack_addr);
	printf("heap addr: %p\n", heap_addr);
	printf("heap data: %d\n", *heap_addr);
}

