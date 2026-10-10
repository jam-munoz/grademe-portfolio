#include <stddef.h>

void	*gm_memmove(void *dst, const void *src, size_t n)
{
	unsigned char *d = dst;
	const unsigned char *s = src;

	if (d < s)
	{
		while (n > 0)
		{
			*d = *s;
			d++;
			s++;
			n--;
		}
	}
	else
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	return dst;
}
