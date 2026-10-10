#include <stddef.h>

char	*gm_strncat(char *dst, const char *src, size_t n)
{
	int i;
	char *p = dst;
	
	while (*dst)
		dst++;
	for (i = 0; n > 0 && src[i]; i++, n--)
		dst[i] = src[i];
	dst[i] = '\0';
	return p;
}
