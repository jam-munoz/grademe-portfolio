// digit_sum(n) is the last digit of n plus digit_sum(n / 10).
// The sign is dropped, and n itself is never negated: -INT_MIN does not fit.
int	digit_sum(int n)
{
	if (n == -2147483647 - 1)
		return 47;

	int nb = n * ((n >> 31) | 1);

	if (nb < 1)
		return 0;
	
	return nb % 10 + digit_sum(nb / 10);
}
