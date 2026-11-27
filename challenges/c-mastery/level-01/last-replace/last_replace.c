#include <unistd.h>

void	ft_putstr(char *str);
int	ft_strlen(const char *str);

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		ft_putstr("wrong number of arguments\n");
		return 0;
	}
	if (argv[2][1] || argv[3][1])
	{
		ft_putstr("\n");
		return 0;
	}
	int len = ft_strlen(argv[1]) - 1;
	for (; len >= 0; len--)
	{
		if (argv[1][len] == argv[2][0])
		{
			argv[1][len] = argv[3][0];
			break;
		}
	}
	ft_putstr(argv[1]);
	ft_putstr("\n");
}

int	ft_strlen(const char *str)
{
	const char	*p;

	p = str;
	while (*p != '\0')
		p++;
	return (p - str);
}

void	ft_putstr(char *str)
{
	char	*p;

	p = str;
	while (*p != '\0')
		p++;
	write(STDOUT_FILENO, str, p - str);
}