char	*gm_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	if (*s == c)
		return (char *)s;
	else
		return (void *)0;
}
