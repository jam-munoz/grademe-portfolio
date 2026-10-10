#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlen(const char *str);
char	*ft_itoa(int nb);
// Returns a fresh "name#id" string; the caller frees it once.
// The decimal digits are staged in a scratch buffer, then copied into the label.

char	*build_label(const char *name, int id)
{
	if (name == NULL)
		return NULL;
	char *nptr = ft_itoa(id);
	char *str = malloc((ft_strlen(name) + ft_strlen(nptr) + 2) * sizeof(char));
	if (str == NULL)
	{
		free(nptr);
		return NULL;
	}
	int i = 0;
	for (; name[i]; i++)
		str[i] = name[i];
	str[i++] = '#';
	for (int j = 0; nptr[j]; i++, j++)
		str[i] = nptr[j];
	free(nptr);
	str[i] = '\0';
	return str;
}

size_t	ft_strlen(const char *str)
{
	const char	*p;

	p = str;
	while (*p != '\0')
		p++;
	return (p - str);
}

int	ft_digit_count(unsigned int n)
{
	if (n < 10)
		return (1);
	if (n < 100)
		return (2);
	if (n < 1000)
		return (3);
	if (n < 10000)
		return (4);
	if (n < 100000)
		return (5);
	if (n < 1000000)
		return (6);
	if (n < 10000000)
		return (7);
	if (n < 100000000)
		return (8);
	if (n < 1000000000)
		return (9);
	return (10);
}

char	*ft_itoa(int nb)
{
	unsigned int	n;
	int				digits;
	int				start;
	char			*str;

	n = nb;
	start = 0;
	if (nb < 0)
	{
		n = -n;
		start = 1;
	}
	digits = ft_digit_count(n) + start;
	str = malloc(digits + 1);
	if (str == NULL)
		return (NULL);
	if (nb < 0)
		str[0] = '-';
	str[digits--] = '\0';
	while (digits >= start)
	{
		str[digits--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
