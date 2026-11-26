#include <unistd.h>

void	ft_putstr(char *str);
int	ft_strcmp(const char *s1, const char *s2);

int	main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		if (!ft_strcmp("-l", argv[i]))
			ft_putstr("Option l\n");
		else if (!ft_strcmp("-c", argv[i]))
			ft_putstr("Option c\n");
		else if (!ft_strcmp("-p", argv[i]))
		{
			ft_putstr("Option p with arg ");
			ft_putstr(argv[i + 1]);
			i++;
			ft_putstr("\n");
		}
		else if (!ft_strcmp("--", argv[i]) || argv[i][0] != '-')
			return 0;
	}
}

void	ft_putstr(char *str)
{
	char	*p;

	p = str;
	while (*p != '\0')
		p++;
	write(STDOUT_FILENO, str, p - str);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (*p1 && *p1 == *p2)
	{
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}
