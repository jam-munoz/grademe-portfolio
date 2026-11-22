#include <unistd.h>
void	ft_putstr(char *str);
void ft_putnbr(int nb);

int	main(void)
{
	for (int i = 1; i <= 100; i++)
	{
		if (i % 15 == 0)
			ft_putstr("FizzBuzz\n");
		else if (i % 5 == 0)
			ft_putstr("Buzz\n");
		else if (i % 3 == 0)
			ft_putstr("Fizz\n");
		else
			ft_putnbr(i);
	}
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

void ft_putnbr(int nb)
{
	char	buf[12];
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
	buf[11] = '\n';
	write(1, buf + i, 12 - i);
}