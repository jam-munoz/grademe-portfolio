#include <stdlib.h>

int	digit_count(unsigned int nb);

char *int_to_str(int nb)
{
	unsigned int n = nb;
	int start = 0;
	
	if (nb < 0)
	{
		n = -n;
		start = 1;
	}
	int digits = digit_count(n) + start;
	char *str = malloc((digits + 1) * sizeof(int));
	str[digits--] = '\0';
	while (digits >= start)
	{
		str[digits--] = n % 10 + '0';
		n /= 10;
	}
	if (nb < 0)
		str[0] = '-';
	return str;
}

int	digit_count(unsigned int n)
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
	return (10);
}