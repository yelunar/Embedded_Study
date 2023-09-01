#include <unistd.h>

void main()
{
	char ch = 'a';

	write(1, &ch, sizeof(ch));
}

