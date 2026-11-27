#include <stddef.h>

char	*gm_strrchr(const char *s, int c)
{
	int len = 0;
	for (; s[len]; len++)
		;
	for ( ; len >= 0; len--)
	{
		if (s[len] == (char)c)
		{
			return (char *)(s + len);
		}
	}
	return NULL;
}
