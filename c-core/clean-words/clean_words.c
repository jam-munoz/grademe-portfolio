#include <unistd.h>

int	ft_isspace(char c);
int	ft_strlen(char *str);

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(STDOUT_FILENO, "wrong number of arguments\n", 26);
		return 0;
	}
	char *str = argv[1];
	int j = 0;
	int len = ft_strlen(str);

	for (int i = 0; i < len; i++)
	{
		if (!ft_isspace(str[i]))
		{
			for (; i < len && !ft_isspace(str[i]); i++, j++)
			{
				str[j] = str[i];
			}
			str[j++] = ' ';
		}
	}
	str[j - 1] = '\n';
	write(STDOUT_FILENO, str, j);
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
