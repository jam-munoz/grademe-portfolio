#include <unistd.h>

void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int	ft_atoi(const char *nptr);
int	ft_isdigit(int c);
int	ft_isspace(char c);
int ft_isop(int c);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Error\n");
		return 0;
	}
	int stack[1024];
	int idx = 0;
	char *nptr = argv[1];
	for (int i = 0; nptr[i];)
	{
		if (ft_isdigit(nptr[i]))
		{
			stack[idx++] = ft_atoi(&nptr[i]);
			while (ft_isdigit(nptr[i]))
				i++;
		}
		else if (ft_isspace(nptr[i]))
			i++;
		else if (ft_isop(nptr[i]))
		{
			idx--;
			if (idx < 1)
			{
				ft_putstr("Error\n");
				return 0;
			}
			int b = stack[idx--];
			int a = stack[idx];
			switch (nptr[i])
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
			i++;
		}
		else
		{
			ft_putstr("Error\n");
			return 0;
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

int ft_isop(int c)
{
	return (c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '%');
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isspace(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
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
