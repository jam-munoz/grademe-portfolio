#include <unistd.h>

void	ft_putstr(char *str)
{
	char	*p;

	p = str;
	while (*p != '\0')
		p++;
	write(1, str, p - str);
}

int	is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 5;
	while (i * i <= nb)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	sum;

	if (!str)
		return (0);
	i = 0;
	sign = 1;
	sum = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		sum *= 10;
		sum += str[i] - '0';
		i++;
	}
	return (sum * sign);
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
	write(1, buf + i, 11 - i);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("0\n");
		return 0;
	}
	long sum = 0;
	int n = ft_atoi(argv[1]);

	for (int i = 2; i <= n; i++)
	{
		if (is_prime(i))
			sum += i;
	}
	ft_putnbr(sum);
	ft_putstr("\n");
}
