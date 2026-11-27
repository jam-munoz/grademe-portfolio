#include <stdlib.h>

void	*gm_calloc(size_t nmemb, size_t size)
{
	size_t len;

	if (__builtin_mul_overflow(nmemb, size, &len))
		return NULL;

	void *arr = malloc(len);
	if (arr == NULL)
		return NULL;

	unsigned char *out = arr;
	for (unsigned int i = 0; i < len; i++)
		out[i] = 0x0;

	return arr;
}
