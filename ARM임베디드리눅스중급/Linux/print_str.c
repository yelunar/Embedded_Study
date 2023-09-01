#include <unistd.h>

void main()
{
	char str[] = { 'R','e','a','l',
		      'L','i','n','u','x'};

	for (int i = 0; i < 9; i++)
		write(1, &str[i], sizeof(char));
}

