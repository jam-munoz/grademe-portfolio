#include <stdbool.h>
#include <unistd.h>

bool	ft_isupper(int c);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(STDOUT_FILENO, "wrong number of arguments\n", 26);
		return 0;
	}
	char *str = argv[1];
	int i = 0;

	for (; str[i]; i++)
	{
		if (ft_isupper(str[i]))
		{
			write(STDOUT_FILENO, str, i);
			str[i] = str[i] + 32;
			i--;
			str[i] = '_';
			str += i;
			i = 0;
		}
	}
	str[i] = '\n';
	write(STDOUT_FILENO, str, i + 1);
}

bool	ft_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}
