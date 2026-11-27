#include <stddef.h>

void	*gm_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d = dst;
	const unsigned char *s = src;

	for (unsigned int i = 0; i < n; i++)
	{
		d[i] = s[i];
	}
	return dst;
}
