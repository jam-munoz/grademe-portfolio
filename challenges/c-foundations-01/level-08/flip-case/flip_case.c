#include <unistd.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
int ft_lower(char c);
int ft_upper(char c);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("wrong number of arguments\n");
		return 0;
	}

	char *str = argv[1];
	for (int i = 0; str[i]; i++)
	{
		if (ft_lower(str[i]))
			str[i] -= 32;
		else if (ft_upper(str[i]))
			str[i] += 32;
	}
	ft_putstr(str);
	ft_putchar('\n');
	return (0);
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_lower(char c)
{
	if ('a' <= c && c <= 'z')
		return 1;
	else
		return 0;
}

int ft_upper(char c)
{
	if ('A' <= c && c <= 'Z')
		return 1;
	else
		return 0;
}