#include <stddef.h>

int	gm_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *p1 = s1;
	const unsigned char *p2 = s2;
	
	for (unsigned int i = 0; i < n; i++)
	{
		if (p1[i] != p2[i])
			return p1[i] - p2[i];
	}
	return 0;
}
