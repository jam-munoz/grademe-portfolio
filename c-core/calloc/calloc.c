#include <stdlib.h>
#include <stddef.h>

void	*gm_calloc(size_t nmemb, size_t size)
{
	size_t n;
	if (__builtin_mul_overflow(nmemb, size, &n))
		return NULL;
	unsigned char *p = malloc(n);
	if (p == NULL)
		return NULL;
	for (unsigned long i = 0; i < n; i++)
	{
		p[i] = 0x0;
	}
	return (void *)p;
}
