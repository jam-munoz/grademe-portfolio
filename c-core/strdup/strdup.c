#include <stdlib.h>

int	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);

char *gm_strdup(const char *src)
{
	int len = ft_strlen(src);
	char *str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return NULL;
	return ft_strcpy(str, src);
}

int	ft_strlen(const char *str)
{
	const char	*p;

	p = str;
	while (*p != '\0')
		p++;
	return (p - str);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*p;

	p = dest;
	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return (dest);
}