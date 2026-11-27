#include <unistd.h>

int	gm_puts(const char *s)
{
	int len = 0;

	while (s[len])
		len++;

	char buf[1024];
	for (int i = 0; i < len; i++)
		buf[i] = s[i];
	buf[len] = '\n';

	write(STDOUT_FILENO, buf, len + 1);
	return 0;
}
