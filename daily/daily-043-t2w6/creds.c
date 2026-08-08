int	ft_strcmp(const char *s1, const char *s2);
int	ft_strlen(const char *str);

int	is_default(const char *user, const char *pass)
{
	(void)pass;
	if (ft_strcmp(user, "root") == 0 && ft_strcmp(pass, "root") == 0)
		return 1;
	if (ft_strcmp(user, "root") == 0 && ft_strcmp(pass, "12345") == 0)
		return 1;
	if (ft_strcmp(user, "admin") == 0)
		return 1;
	return 0;
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	len;
	int	i;

	len = ft_strlen(s1);
	i = 0;
	while (i <= len)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
