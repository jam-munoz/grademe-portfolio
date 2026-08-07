int is_sep(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return 1;
	else
		return 0;
}

int ft_numeric(char c)
{
	if ('0' <= c && c <= '9')
		return 1;
	else
		return 0;
}

int atoi(const char *str)
{
	int i = 0;
	int sum = 0;
	int sign = 1;

	while (is_sep(str[i]))
		i++;
	
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	while(ft_numeric(str[i]))
	{
		sum *= 10;
		sum += str[i] - '0';
		i++;
	}

	return (sign * sum);
}
