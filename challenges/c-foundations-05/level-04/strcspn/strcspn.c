#include <stddef.h>

size_t	gm_strcspn(const char *s, const char *reject)
{
	int i;
	for (i = 0; s[i]; i++)
	{
		for (int j = 0; reject[j]; j++)
		{
			if (reject[j] == s[i])
				return i;
		}
	}
	return i;
}
