#include <unistd.h>

int	ft_isupper(int c);

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
		if (ft_isupper(str[i]))
		{
			write(STDOUT_FILENO, str, i);
			str += i;
			*str = *str + 32;
			str--;
			*str = '_';
			i = 0;
		}
	}
	if (str[i] == '\0')
	{
		str[i] = '\n';
		write(STDOUT_FILENO, str, i + 1);
	}
}

int	ft_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}
