#include <stdbool.h>
#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr("wrong number of arguments\n");
		return 0;
	}
	bool seen[256] = { false };
	int i, j;
	for (i = 0, j = 0; argv[2][i]; i++)
	{
		for (j = 0; argv[1][j]; j++)
		{
			if (argv[2][i] == argv[1][j] && !seen[(unsigned char)argv[2][i]])
			{
				seen[(unsigned char)argv[2][i]] = true;
				ft_putchar(argv[2][i]);
				break;
			}
		}
	}
	ft_putchar('\n');
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
