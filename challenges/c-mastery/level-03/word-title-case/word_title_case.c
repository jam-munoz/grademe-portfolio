#include <stdbool.h>
#include <unistd.h>

void	ft_putstr(char *str);
bool	ft_isspace(char c);
int	ft_toupper(int c);
int	ft_tolower(int c);

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr("wrong number of arguments\n");
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		bool isword = true;
		for (int j = 0; argv[i][j]; j++)
		{
			if (ft_isspace(argv[i][j]))
				isword = true;
			else if (isword)
			{
				argv[i][j] = ft_toupper(argv[i][j]);
				isword = false;
			}
			else
				argv[i][j] = ft_tolower(argv[i][j]);
		}
		ft_putstr(argv[i]);
		ft_putstr("\n");
	}
}

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	else
		return (c);
}

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

bool	ft_isspace(char c)
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
