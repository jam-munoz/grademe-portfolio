#include <stddef.h>

void	*gm_memchr(const void *s, int c, size_t n)
{
	const unsigned char *p = s;
	for (unsigned int i = 0; i < n; i++)
	{
		if (p[i] == (unsigned char)c)
			return (void *)s + i;
	}
	return (NULL);
}
