void	ft_swap(char *a, char *b);
int	ft_strlen(const char *str);

char *rev_str(char *str)
{
	int end = ft_strlen(str) - 1;

	for (int start = 0; start < end; start++, end--)
		ft_swap(str + start, str + end);
	return str;
}

void	ft_swap(char *a, char *b)
{
	char	temp;

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