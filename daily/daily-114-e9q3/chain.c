char	*ft_strrchr(const char *s, int c);

void	short_chain(char *out, const char *chain)
{
    char *end = ft_strrchr(chain, '>');
    if (end == (void *)0)
    {
        *out = '\0';
        return;
    }
    for (; chain != end && *chain; out++, chain++)
    {
        *out = *chain;
    }
    *out = '\0';
}

char	*ft_strrchr(const char *s, int c)
{
	const char	*start;

	start = s;
	while (*s != '\0')
		s++;
	while (s >= start)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s--;
	}
	return ((void *)0);
}
