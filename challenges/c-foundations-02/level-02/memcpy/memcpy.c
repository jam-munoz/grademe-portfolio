#include <stddef.h>

void	*gm_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d = dst;
	const unsigned char *s = src;
	while (n > 0)
	{
		*d++ = *s++;
		n--;
	}
	return dst;
}
