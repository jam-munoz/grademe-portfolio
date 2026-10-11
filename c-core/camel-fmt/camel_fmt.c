#include <unistd.h>

int	ft_toupper(int c);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(STDOUT_FILENO, "wrong number of arguments\n", 26);
		return 0;
	}
	char *str = argv[1];
	int i;
	for (i = 0; str[i]; i++)
	{
		if (str[i] == '_')
		{
			write(STDOUT_FILENO, str, i);
			str += i + 1;
			*str = ft_toupper(*str);
			i = 0;
		}
	}
	str[i] = '\n';
	write(STDOUT_FILENO, str, i + 1);
}

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	else
		return (c);
}