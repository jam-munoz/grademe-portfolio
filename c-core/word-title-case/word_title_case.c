#include <stdbool.h>
#include <unistd.h>

bool	ft_isspace(char c);
int	ft_toupper(int c);
int	ft_tolower(int c);

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(STDOUT_FILENO, "wrong number of arguments\n", 26);
		return 0;
	}
	bool word;
	int i;
	for (int ac = 1; ac < argc; ac++)
	{
		word = true;
		for (i = 0; argv[ac][i]; i++)
		{
			if (ft_isspace(argv[ac][i]))
			{
				word = true;
			}
			else if (word)
			{
				argv[ac][i] = ft_toupper(argv[ac][i]);
				word = false;
			}
			else
			{
				argv[ac][i] = ft_tolower(argv[ac][i]);
			}
		}
		argv[ac][i] = '\n';
		write(STDOUT_FILENO, argv[ac], i + 1);
	}
}

bool	ft_isspace(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
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
