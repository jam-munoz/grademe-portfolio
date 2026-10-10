#include <stdlib.h>

int	ft_strlen(const char *str);
// Returns a fresh block holding dir, then '/' when dir needs one, then name.
// The caller frees the result. The paths are already right, the allocations are not.
char	*build_path(const char *dir, const char *name)
{
	if (dir == NULL || name == NULL)
		return NULL;
	char *str = malloc((ft_strlen(dir) + ft_strlen(name) + 2) * sizeof(char));
	if (str == NULL)
		return NULL;
	int i = 0;
	if (*dir)
	{
		for (; dir[i]; i++)
			str[i] = dir[i];
		if (str[i - 1] != '/')
			str[i++] = '/';
	}
	for (int j = 0; name[j]; j++, i++)
		str[i] = name[j];
	str[i] = '\0';
	return str;
}

int	ft_strlen(const char *str)
{
	const char	*p = str;

	while (*p != '\0')
		p++;
	return (p - str);
}

