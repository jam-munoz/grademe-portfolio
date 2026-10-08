#include <stddef.h>

size_t	gm_strcspn(const char *s, const char *reject)
{
	size_t i;
	for (i = 0; s[i]; i++)
	{
		for (size_t j = 0; reject[j]; j++)
		{
			if (s[i] == reject[j])
				return i;
		}
	}
	return i;
}
