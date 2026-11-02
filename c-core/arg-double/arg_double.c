#include <unistd.h>

int	ft_atoi(const char *nptr);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr("wrong number of arguments\n");
		return 0;
	}
	int n = ft_atoi(argv[1]);
	ft_putnbr(n * 2);
	ft_putstr("\n");
}

void	ft_putstr(char *str)
{
	char	*p;

	p = str;
	while (*p != '\0')
		p++;
	write(STDOUT_FILENO, str, p - str);
}

void	ft_putnbr(int nb)
{
	char			buf[11];
	int				i;
	unsigned int	n;

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
	write(STDOUT_FILENO, buf + i, 11 - i);
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
