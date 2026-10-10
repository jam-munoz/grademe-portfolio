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
			d[n - 1] = s[n - 1];
			n--;
		}
	return dst;
}
