#include <stdlib.h>
#include <stddef.h>

int	ft_strlen(const char *str);
// str_join returns a fresh string holding the n strings of parts, separated by
// sep. The caller frees it.
char	*str_join(char **parts, size_t n, char sep)
{
	if (n == 0)
	{
		char *str = malloc(1);
		*str = '\0';
		return str;
	}
	int len = n;
	int i, j, k;
	for (unsigned int i = 0; i < n; i++)
	{
		len += ft_strlen(parts[i]);
	}
	char *str = malloc((len) * sizeof(char));
	if (str == NULL)
		return NULL;
	*str = '\0';	
	for (i = 0, j = 0; i < len; i++, j++)
	{
		for (k = 0; parts[j][k]; i++, k++)
		{
			str[i] = parts[j][k];
		}
		str[i] = sep;
	}
	str[i - 1] = '\0';
	return str;
}

int	ft_strlen(const char *str)
{
	const char	*p;

	p = str;
	while (*p != '\0')
		p++;
	return (p - str);
}
