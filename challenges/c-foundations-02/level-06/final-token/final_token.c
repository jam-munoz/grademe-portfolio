#include <unistd.h>

void	ft_putstr(char *str);
void	ft_putstr2(char *str);
void	ft_putchar(char c);

int ft_sep(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return 1;
	else
		return 0;
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		ft_putstr("wrong number of arguments\n");
		return 0;
	}

	int i = 0;
	char *str = argv[1];
	for(; str[i]; i++) ;
	i--;
	while (ft_sep(str[i]))
		i--;
	while (!ft_sep(str[i]) && i >= 0)
		i--;
	i++;
	ft_putstr2(&str[i]);
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

void	ft_putstr2(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !ft_sep(str[i]))
	{
		i++;
	}
	write(1, str, i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
