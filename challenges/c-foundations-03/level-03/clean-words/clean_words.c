#include <unistd.h>

void	ft_putchar(char c);
int		ft_isspace(char c);
void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("wrong number of arguments\n");
		return 0;
	}
	char *str = argv[1];
	int first_word = 1;
	for (int i = 0; str[i];)
	{
		if (!ft_isspace(str[i]))
		{
			if (!first_word)
				ft_putchar(' ');
			else
				first_word = 0;
			while (!ft_isspace(str[i]) && str[i])
				ft_putchar(str[i++]);
		}
		else
			i++;
	}
	ft_putchar('\n');
}

void	ft_putstr(char *str)
{
	char	*p;

	p = str;
	while (*p != '\0')
		p++;
	write(STDOUT_FILENO, str, p - str);
}

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
}

int	ft_isspace(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}
