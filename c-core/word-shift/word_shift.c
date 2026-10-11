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
	char *words = argv[1];
	while (*words && !ft_isspace(*words))
		words++;
	while (ft_isspace(*words))
		words++;
	int i;
	for (i = 0; words[i]; )
	{
		if (ft_isspace(words[i]))
		{
			str[i++] = ' ';
			while (ft_isspace(words[i]))
				words++;
		}
		else
		{
			str[i] = words[i];
			i++;
		}
	}
	if (i > 0)
		str[i++] = ' ';
	for (int j = 0; argv[1][j] && !ft_isspace(argv[1][j]); i++, j++)
	{
		str[i] = argv[1][j];
	}
	str[i] = '\n';
	write(STDOUT_FILENO, str, i + 1);
}

bool	ft_isspace(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}