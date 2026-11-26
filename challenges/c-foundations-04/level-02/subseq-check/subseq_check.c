#include <unistd.h>

void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr("wrong number of arguments\n");
		return 0;
	}
	int j = 0;
	for (int i = 0; argv[2][i]; i++)
	{
		if (argv[2][i] == argv[1][j])
			j++;
	}
	if (argv[1][j] == '\0')
		ft_putstr("yes\n");
	else
		ft_putstr("no\n");
}

void	ft_putstr(char *str)
{
	char	*p;

	p = str;
	while (*p != '\0')
		p++;
	write(STDOUT_FILENO, str, p - str);
}
