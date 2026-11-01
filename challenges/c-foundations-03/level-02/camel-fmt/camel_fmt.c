#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int	ft_toupper(int c);

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
		if (str[i] == '_')
		{
			i++;
			ft_putchar(ft_toupper(str[i]));
		}
		else
			ft_putchar(str[i]);
	}
	ft_putchar('\n');
}

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	else
		return (c);
}

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
}

void	ft_putstr(char *str)
{
	char	*p;

	p = str;
	while (*p != '\0')
		p++;
	write(STDOUT_FILENO, str, p - str);
}
