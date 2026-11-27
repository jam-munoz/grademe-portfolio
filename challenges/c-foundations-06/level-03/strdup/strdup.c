#include <stdlib.h>

char *gm_strdup(const char *src)
{
	int len = 0;
	while (src[len])
		len++;
	
	char *str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return NULL;
	for (int i = 0; i < len; i++)
	{
		str[i] = src[i];
	}
	str[len] = '\0';
	return str;
}
