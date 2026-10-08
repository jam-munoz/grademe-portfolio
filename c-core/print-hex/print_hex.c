#include <unistd.h>

int	ft_atoi(const char *nptr);
int hex_digit_count(unsigned int n);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(STDOUT_FILENO, "wrong number of arguments\n", 26);
		return 0;
	}
	unsigned int n = ft_atoi(argv[1]);
	char hex_values[] = "0123456789abcdef";
	int digits = hex_digit_count(n);
	int i = digits;
	char str[digits + 1];
	
	str[i--] = '\n';
	while (i >= 0)
	{
		str[i--] = hex_values[n & 0xF];
		n >>= 4;
	}
	write(STDOUT_FILENO, str, digits + 1);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	sum;

	if (!nptr)
		return (0);
	sign = 1;
	sum = 0;
	while (*nptr == ' ' || (9 <= *nptr && *nptr <= 13))
		nptr++;
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
	return (sum * sign);
}

int hex_digit_count(unsigned int n)
{
	int count = 0;

	while (n > 0)
	{
		n >>= 4;
		count++;
	}
	return count;
}
