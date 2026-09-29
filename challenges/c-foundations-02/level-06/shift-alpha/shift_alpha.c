#include <unistd.h>

void	ft_putstr(char *str);
int	ft_isalpha(int c);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("wrong number of arguments\n");
		return 0;
	}
	char *str = argv[1];
	int i;

	for (i = 0; str[i]; i++)
	{
		if (ft_isalpha(str[i]))
		{
			str[i] = str[i] + 1;
			if (str[i] == '[' || str[i] == '{')
			{
				str[i] = str[i] - 26;
			}
		}
	}
	ft_putstr(str);
	ft_putstr("\n");
}

void	ft_putstr(char *str)
{
	char	*p;

	p = str;
	while (*p != '\0')
		p++;
	write(1, str, p - str);
}

int	ft_isalpha(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}