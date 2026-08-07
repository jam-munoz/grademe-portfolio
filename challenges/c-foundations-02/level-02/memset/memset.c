#include <stddef.h>

void	*memset(void *s, int c, size_t n)
{
	if (n == 0)
		return s;
	unsigned char *ptr = (unsigned char *)s;
	size_t i;
	for (i = 0; i < n; i++)
	{
		ptr[i] = (unsigned char)c;
	}
	return (s);
}
