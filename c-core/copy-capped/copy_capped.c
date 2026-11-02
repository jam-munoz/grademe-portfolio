#include <stddef.h>

// Copies src into dst, a buffer of cap bytes, without writing past it.
// Returns the length of src.
size_t	copy_capped(char *dst, const char *src, size_t cap)
{
	unsigned int i;
	for (i = 0; (i + 1) < cap && src[i]; i++)
	{
		dst[i] = src[i];
	}
	if (cap > 0)
		dst[i] = '\0';
	while (src[i])
		i++;
	return i;
}
