#include <stdbool.h>
#include <unistd.h>

bool	ft_isspace(char c);
bool	ft_ispunct(char c);
int	ft_toupper(int c);
int	ft_tolower(int c);
int	ft_strlen(const char *s);

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
		int len = ft_strlen(argv[ac]);
		for (i = len - 1; i >= 0; i--)
		{
			if (ft_isspace(argv[ac][i]) || ft_ispunct(argv[ac][i]))
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
		argv[ac][len] = '\n';
		write(STDOUT_FILENO, argv[ac], len + 1);
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

int	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p != '\0')
		p++;
	return (p - s);
}


bool	ft_ispunct(char c)
{
	return (('!' <= c && c <= '/') || (':' <= c && c <= '@')
		|| ('[' <= c && c <= '`') || ('{' <= c && c <= '~'));
}

