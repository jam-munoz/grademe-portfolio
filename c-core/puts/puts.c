#include <unistd.h>

int	puts(const char *s)
{
	int len = 0;
	for (; s[len]; len++);
	write(1, s, len);
	write(1, "\n", 1);
	return (0);
}
