int	ft_digit_count(long nb);
// out receives cents rendered as a decimal amount with exactly two decimals.
// Returns how many characters were written, the terminator excluded.
int	money_format(long cents, char *out)
{
	int digits = ft_digit_count(cents) + 1;
	unsigned long long n = cents;
	if (cents < 0)
	{
		digits++;
		out[0] = '-';
		n = -n;
	}
	
	int len = digits;
	out[len--] = '\0';
	out[len--] = (n % 10) + '0';
	n /= 10;
	out[len--] = (n % 10) + '0';
	n /= 10;
	out[len--] = '.';
	out[len--] = (n % 10) + '0';
	n /= 10;
	while (n > 0)
	{
		out[len--] = (n % 10) + '0';
		n /= 10;
	}
	return digits;
}

int	ft_digit_count(long nb)
{
	unsigned long long n = nb;

	if (nb < 0)
		n = -nb;

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
	if (n < 10000000000)
		return (10);
	if (n < 100000000000)
		return (11);
	if (n < 1000000000000)
		return (12);
	if (n < 10000000000000)
		return (13);
	if (n < 100000000000000)
		return (14);
	if (n < 1000000000000000)
		return (15);
	if (n < 10000000000000000)
		return (16);
	if (n < 100000000000000000)
		return (17);
	if (n < 1000000000000000000)
		return (18);
	return (19);
}