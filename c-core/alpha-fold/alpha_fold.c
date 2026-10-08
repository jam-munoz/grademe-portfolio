#include <unistd.h>

int	ft_islower(int c);

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(STDOUT_FILENO, "wrong number of arguments\n", 26);
		return 0;
	}
	int i;
	char *str = argv[1];
	for (i = 0; str[i]; i++)
	{
		if (ft_islower(str[i]))
		{
			str[i] = 219 - str[i];
		}
	}
	str[i] = '\n';
	write(STDOUT_FILENO, str, i + 1);
}

int	ft_islower(int c)
{
	return ('a' <= c && c <= 'z');
}
