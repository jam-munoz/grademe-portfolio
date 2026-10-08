#include <stdlib.h>
#include <unistd.h>

int	ft_isspace(char c);
int	ft_strlen(char *str);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(STDOUT_FILENO, "wrong number of arguments\n", 26);
		return 0;
	}
	int len = ft_strlen(argv[1]);
	int i, k;
	int j = len;
	char *str = argv[1];
	char *cpy = malloc((len + 1) * sizeof(char));

	for (i = 0; i < len && j > 0; j--)
	{
		if (!ft_isspace(str[j]))
		{
			k = 0;
			while (!ft_isspace(str[j]) && j >= 0)
				j--;
			while (!ft_isspace(str[j + 1 + k]) && j + 1 + k < len)
			{
				cpy[i] = str[j + 1 + k];
				i++;
				k++;
			}
			cpy[i++] = ' ';
		}
	}
	cpy[i - 1] = '\n';
	write(STDOUT_FILENO, cpy, i);
	free(cpy);
	return 0;
}

int	ft_isspace(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

int	ft_strlen(char *str)
{
	char	*p;

	p = str;
	while (*p != '\0')
		p++;
	return (p - str);
}

