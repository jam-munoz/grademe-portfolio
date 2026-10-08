#include <stddef.h>

char	*gm_strncat(char *dst, const char *src, size_t n)
{
	char *p = dst;
	
	while (*dst != '\0')
		dst++;
	while (*src && n > 0)
	{
		*dst = *src;
		dst++;
		src++;
		n--;
	}
	*dst = '\0';
	return p;
}
