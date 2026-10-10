#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlen(const char *s);
// str_join returns a fresh string holding the n strings of parts, separated by
// sep. The caller frees it.
char	*str_join(char **parts, size_t n, char sep)
{
	if (n == 0)
	{
		char *str = malloc(sizeof(char));
		*str = '\0';
		return str;
	}
	int len = n;
	for (unsigned int i = 0; i < n; i++)
		len += ft_strlen(parts[i]);
	char *str = malloc((len) * sizeof(char));
	if (str == NULL)
		return NULL;
	int idx = 0;
	for (unsigned int i = 0; i < n; i++)
	{
		for (unsigned int j = 0; parts[i][j]; j++)
		{
			str[idx++] = parts[i][j];
		}
		str[idx++] = sep;
	}
	str[idx - 1] = '\0';
	return str;
}

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p != '\0')
		p++;
	return (p - s);
}
