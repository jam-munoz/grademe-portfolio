#include <stdbool.h>
#include <unistd.h>

bool	ft_isspace(char c);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(STDOUT_FILENO, "wrong number of arguments\n", 26);
		return 0;
	}
	char str[4096];
	while (ft_isspace(*argv[1]))
		argv[1]++;
	int i, j = 0;
	for (i = 0; argv[1][i]; )
	{
		if (!ft_isspace(argv[1][i]))
		{
			if (j != 0 && (j & 0x7) == 0)
				str[j++] = ' ';
			for (; j != 0 && (j & 0x7) != 0; j++)
				str[j] = ' ';
			while (argv[1][i] && !ft_isspace(argv[1][i]))
				str[j++] = argv[1][i++];
		}
		else
			i++;
	}
	str[j] = '\n';
	write(STDOUT_FILENO, str, j + 1);
}

bool	ft_isspace(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}