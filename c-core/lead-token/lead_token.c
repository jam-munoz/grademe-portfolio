#include <unistd.h>

void	ft_putstr(char *str);
int ft_isspace(char c);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("wrong number of arguments\n");
		return 0;
	}
	char *str = argv[1];
	while (*str && ft_isspace(*str))
		str++;
	int i;
	for (i = 0; str[i] && !ft_isspace(str[i]); i++)
		;
	str[i++] = '\n';
	write(1, str, i);
}

void	ft_putstr(char *str)
{
	char	*p;

	p = str;
	while (*p != '\0')
		p++;
	write(STDOUT_FILENO, str, p - str);
}

int ft_isspace(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return 1;
	else
		return 0;
}