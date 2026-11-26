#include <unistd.h>

int	ft_atoi(const char *nptr);
void	ft_putnbr(int nb);

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(STDOUT_FILENO, "0\n", 2);
		return 0;
	}
	int sum = 0;
	for (int i = 1; i < argc; i++)
	{
		sum += ft_atoi(argv[i]);
	}
	ft_putnbr(sum);
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

void	ft_putnbr(int nb)
{
	char			buf[12];
	int				i;
	unsigned int	n;

	buf[11] = '\n';
	i = 11;
	n = nb;
	if (nb < 0)
		n = -n;
	while (n >= 10)
	{
		buf[--i] = (n % 10) + '0';
		n = n / 10;
	}
	buf[--i] = n + '0';
	if (nb < 0)
		buf[--i] = '-';
	write(STDOUT_FILENO, buf + i, 12 - i);
}
