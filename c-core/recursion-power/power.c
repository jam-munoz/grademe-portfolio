int	power(int base, int exp)
{
	if (exp < 0)
		return -1;
	if (base == 1 || exp == 0)
		return 1;
	if (base == 0)
		return 0;
	long n = base * ((base >> 31) | 1);
	if (base < 0 && exp % 2 != 0)
		return -n * power(n, exp - 1);
	return n * power(n, exp - 1);
}