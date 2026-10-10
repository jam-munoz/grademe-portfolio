#include <stdlib.h>

int digit_count(unsigned int n, int base);

char *int_to_str_base(int value, int base)
{
	if (base < 2 || 16 < base)
		return NULL;
	unsigned int n = value;
	int start = 0;
	
	if (value < 0 && base == 10)
	{
		n = -n;
		start = 1;
	}
	int digits = digit_count(n, base) + start;
	char *str = malloc((digits + 1) * sizeof(int));
	char hex_digits[] = "0123456789abcdef";
	str[digits--] = '\0';
	if (base == 2 || base == 4 || base == 8 || base == 16)
	{
		int shift;
		switch (base)
		{
			case 2: shift = 1;
				break;
			case 4: shift = 2;
				break;
			case 8: shift = 3;
				break;
			case 16: shift = 4;
				break;
		}
		base--;
		while (digits >= start)
		{
			str[digits--] = hex_digits[n & base];
			n >>= shift;
		}
	}
	else
	{
		while (digits >= start)
		{
			str[digits--] = hex_digits[n % base];
			n /= base;
		}
	}
	if (value < 0 && base == 10)
		str[0] = '-';
	return str;
}

static int	digit_count_ten(unsigned int n)
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

int digit_count(unsigned int n, int base)
{
	if (base == 10)
		return digit_count_ten(n);

	int digits = 0;

	if (base == 2 || base == 4 || base == 8 || base == 16)
	{
		int shift;
		switch (base)
		{
			case 2: shift = 1;
				break;
			case 4: shift = 2;
				break;
			case 8: shift = 3;
				break;
			case 16: shift = 4;
				break;
		}
		while (n > 0)
		{
			n >>= shift;
			digits++;
		}
	}
	else
	{
		while (n > 0)
		{
			n /= base;
			digits++;
		}
	}
	return digits;
}
