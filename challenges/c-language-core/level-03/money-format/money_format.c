int	digit_count(long n);

int	money_format(long money, char *out)
{
	unsigned long n = money;
	int start = 0;
	if (money < 0)
	{
		out[0] = '-';
		n = -n;
		start = 1;
	}
	int cents = n % 100;
	n /= 100;
	int digits = digit_count(n) + 3 + start;
	int len = digits;
	
	out[len--] = '\0';
	out[len--] = cents % 10 + '0';
	out[len--] = cents / 10 + '0';
	out[len--] = '.';
	while (len >= start)
	{
		out[len--] = n % 10 + '0';
		n /= 10;
	}

	return digits;
}

int	digit_count(long n)
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
	if (n < 10000000000L)
		return (10);
	if (n < 100000000000L)
		return (11);
	if (n < 1000000000000L)
		return (12);
	if (n < 10000000000000L)
		return (13);
	if (n < 100000000000000L)
		return (14);
	if (n < 1000000000000000L)
		return (15);
	if (n < 10000000000000000L)
		return (16);
	if (n < 100000000000000000L)
		return (17);
	if (n < 1000000000000000000L)
		return (18);
	return (19);
}