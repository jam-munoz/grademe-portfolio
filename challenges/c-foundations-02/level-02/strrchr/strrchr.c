#include <stddef.h>

char	*gm_strrchr(const char *s, int c)
{
	const char *p = s;

	while (*s)
		s++;
	while (s >= p)
	{
		if (*s == (unsigned char)c)
			return (char *)s;
		s--;
	}
	return 0;
}
