int gm_atoi(const char *nptr)
{
	int sum = 0;
	int sign = 1;

	while (*nptr == ' ' || (9 <= *nptr && *nptr <= 13))
	{
		nptr++;
	}
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while ('0' <= *nptr && *nptr <= '9')
	{
		sum *= 10;
		sum += *nptr - '0';
		nptr++;
	}
	return sum * sign;
}
