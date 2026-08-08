#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int	ft_atoi(char *str);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("wrong number of arguments\n");
		return 0;
	}
	int n = ft_atoi(argv[1]);
	for (int i = 1; i < 10; i++)
	{
		ft_putnbr(i);
		ft_putstr(" x ");
		ft_putnbr(n);
		ft_putstr(" = ");
		ft_putnbr(i * n);
		ft_putchar('\n');
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	write(1, str, i);
}

void	ft_putnbr(int nb)
{
	char	buf[11];
	int	 i;
	long	n;

	i = 11;
	n = nb;
	if (n < 0)
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

int	ft_atoi(char *str)
{
	if (!str)
		return 0;
	int i = 0;
	int sign = 1;
	int sum = 0;
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

