#include <stddef.h>

int	ft_strlen(const char *str);
int	ft_strcmp(const char *s1, const char *s2);
void	swap(size_t *a, size_t *b);
// out receives the indices 0..n-1 of arr, shortest string first,
// ties broken by bytes then by index. arr itself is never written to.
void	argsort_len(char **arr, size_t n, size_t *out)
{
	int key;
	int nb = n;
	if (n == 0)
		return;
	for (int i = 0; i < nb; i++)
		out[i] = i;
	for (int i = 1; i < nb; i++)
	{
		key = out[i];
		for (int j = i - 1; j >= 0 && (ft_strcmp(arr[out[j]], arr[key]) > 0); j--)
		{
			swap(&out[j + 1], &out[j]);
		}
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	int dif = ft_strlen(s1) - ft_strlen(s2);
	if (dif != 0)
		return dif;
	while (*p1 && *p1 == *p2)
	{
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}

void	swap(size_t *a, size_t *b)
{
	size_t	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strlen(const char *str)
{
	const char	*p;

	p = str;
	while (*p != '\0')
		p++;
	return (p - str);
}
