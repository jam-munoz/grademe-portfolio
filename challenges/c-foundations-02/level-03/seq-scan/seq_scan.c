#include <unistd.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
int	ft_strlen(char *str);
char ft_tolower(char c);

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr("wrong number of arguments\n");
		return 0;
	}
	int len = ft_strlen(argv[1]);
	int i = 0, j = 0;

	while(argv[2][j])
	{
		if (ft_tolower(argv[1][i]) == ft_tolower(argv[2][j]))
		{
			i++;
			j++;
		}
		else
			j++;
	}
	if (i == len)
	{
		ft_putstr(argv[1]);
	}
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char ft_tolower(char c)
{
	if ('A' <= c && c <= 'Z')
			c += 32;
	return c;
}
