long ft_gcd(long a, long b);

unsigned int lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return 0;
	return a / ft_gcd(a, b) * b;
}

long ft_gcd(long a, long b)
{
	long r;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
