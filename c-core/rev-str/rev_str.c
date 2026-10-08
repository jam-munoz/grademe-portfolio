int	ft_strlen(char *str);

char *rev_str(char *str)
{
	int end = ft_strlen(str) - 1;
	for (int start = 0; start < end; start++, end--)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
	}
	return str;
}

int	ft_strlen(char *str)
{
	char	*p;

	p = str;
	while (*p != '\0')
		p++;
	return (p - str);
}
