#include <unistd.h>
#include <stdbool.h>

bool 	check_bracket(char *str);
void	ft_putstr(char *str);

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_putstr("wrong number of arguments\n");
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		if (check_bracket(argv[i]))
			ft_putstr("OK\n");
		else
			ft_putstr("Error\n");
	}
}

int	ft_strlen(const char *str)
{
	const char	*p;

	p = str;
	while (*p != '\0')
		p++;
	return (p - str);
}

void	ft_putstr(char *str)
{
	char	*p;

	p = str;
	while (*p != '\0')
		p++;
	write(STDOUT_FILENO, str, p - str);
}

bool check_bracket(char *str)
{
	int start = 0;
	int end = ft_strlen(str) - 1;
	for ( ; start <= end; start++)
	{
		if (str[start] == '{')
		{
			while (str[end] != '}')
			{
				if (end == start)
					return false;
				end--;
			}
			end--;
		}
		else if (str[start] == '(')
		{
			while (str[end] != ')')
			{
				if (end == start)
					return false;
				end--;
			}
			end--;
		}
		else if (str[start] == '[')
		{
			while (str[end] != ']')
			{
				if (end == start)
					return false;
				end--;
			}
			end--;
		}
		else if ((str[start] == '}') || (str[start] == ')') || (str[start] == ']'))
			return false;
	}
	return true;
}
