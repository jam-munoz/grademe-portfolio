#include <stddef.h>

int	gm_strncmp(const char *s1, const char *s2, size_t n)
{
	for (unsigned int i = 0; i < n; i++)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i] || !s1[i])
			return (unsigned char)s1[i] - (unsigned char)s2[i];
	}
	return 0;
}
