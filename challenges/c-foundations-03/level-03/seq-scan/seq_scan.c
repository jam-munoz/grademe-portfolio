#include <stdbool.h>
#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int	ft_strlen(const char *str);
int	ft_tolower(int c);

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr("wrong number of arguments\n");
		return 0;
	}
	int len = ft_strlen(argv[1]);
	int i, j;
	int count = 0;
	for (i = 0, j = 0; argv[1][i]; i++)
	{
		for (; argv[2][j]; j++)
		{
			if (ft_tolower(argv[1][i]) == ft_tolower(argv[2][j]))
			{
				count++;
				break;
			}
		}
	}
	if (len == count)
	{
		ft_putstr(argv[1]);
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

int	ft_strlen(const char *str)
{
	const char	*p;

	p = str;
	while (*p != '\0')
		p++;
	return (p - str);
}

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
