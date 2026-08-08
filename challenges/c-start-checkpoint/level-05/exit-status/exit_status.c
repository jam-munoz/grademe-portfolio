#include <limits.h>
#include <unistd.h>

// On success print the sum of the decimal integers in argv, then a newline, and return 0.
// On failure standard output stays empty and the return value is 1, 2 or 3.
long ft_atoi(char *str);
void ft_putnbr(int nb);
void	ft_putchar(char c);
int ft_exit2(char *str);

int	main(int argc, char **argv)
{
	if (argc == 1)
		return 1;

	long sum = 0;
	int i;
	for (i = 1; i < argc; i++)
	{
		if (ft_exit2(argv[i]))
			return 2;
		sum += ft_atoi(argv[i]);
		if (sum > 2147483647 || sum < -2147483647 - 1)
			return 3;
	}
	ft_putnbr(sum);
	ft_putchar('\n');
	return 0;
}

int ft_exit2(char *str)
{
	if(!str || !str[0] || (!str[1] && (str[0] == '+' || str[0] == '-')))
		return 1;
	for (int i = 0; str[i]; i++)
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			i++;
		if (!('0' <= str[i] && str[i] <= '9'))
			return 1;
	}
	return 0;
}

long ft_atoi(char *str)
{
	if (!str)
		return 0;
	int i = 0;
	int sign = 1;
	long sum = 0;
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

void ft_putnbr(int nb)
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}