#include <unistd.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
int	ft_islower(int c);
int	ft_isupper(int c);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("wrong number of arguments\n");
		return 0;
	}
	char *str = argv[1];
	int i, j, n;
	for (i = 0; str[i]; i++)
	{
		if (ft_islower(str[i]))
			n = str[i] - 'a';
		else if (ft_isupper(str[i]))
			n = str[i] - 'A';
		else
			n = 1;
		for(j = 0; j < n; j++)
			ft_putchar(str[i]);
	}
	ft_putchar('\n');
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

int	ft_islower(int c)
{
	return ('a' <= c && c <= 'z');
}

int	ft_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}
