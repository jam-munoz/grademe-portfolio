#include <stddef.h>

char	*gm_strncpy(char *dst, const char *src, size_t n)
{
	char *ret = dst;

	while (n > 0 && *src)
	{
		*dst = *src;
		dst++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*dst = 0;
		dst++;
		n--;
	}
	return ret;
}
