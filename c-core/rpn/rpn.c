#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str);
void	ft_putnbr(int nb);
bool	ft_isspace(char c);
bool	ft_isdigit(int c);
bool	ft_isop(int c);
int		ft_atoi(char *str);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Error\n");
		return 0;
	}
	int stack[512] = { 0 };
	int idx = 0;
	char *nptr = argv[1];
	while (*nptr != '\0')
	{
		if (ft_isdigit(*nptr))
		{
			stack[idx++] = ft_atoi(&*nptr);
			while (ft_isdigit(*nptr))
				nptr++;
		}
		else if (ft_isspace(*nptr))
		{
			while (ft_isspace(*nptr))
				nptr++;
		}
		else if (ft_isop(*nptr))
		{
			if (idx < 2)
			{
				ft_putstr("Error\n");
				return 0;
			}
			idx--;
			int b = stack[idx--];
			int a = stack[idx];
			switch (*nptr)
			{
				case '+': stack[idx++] = a + b;
					break;
				case '-': stack[idx++] = a - b;
					break;
				case '*': stack[idx++] = a * b;
					break;
				case '/': 
					if (b == 0)
					{
						ft_putstr("Error\n");
						return 0;
					}
					stack[idx++] = a / b;
						break;
				case '%': 
					if (b == 0)
					{
						ft_putstr("Error\n");
						return 0;
					}
					stack[idx++] = a % b;
						break;
				default: break;
			}
			nptr++;
		}
	}
	if (idx > 1)
	{
		ft_putstr("Error\n");
		return 0;
	}
	ft_putnbr(stack[--idx]);
	ft_putstr("\n");
}

bool	ft_isop(int c)
{
	return (c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '%');
}

bool	ft_isspace(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

bool	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
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

