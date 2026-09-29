#include <unistd.h>

void	ft_putstr(char *str);
int	ft_strlen(char *str);

int check_palindrome(char *str)
{
	int len = ft_strlen(str);
	int end = len - 1;
	while (len > 0)
	{
		end = len;
		for (int start = 0; str[start] == str[end]; start++, end--)
		{
			if (start >= end)
				return len;
		}
		len--;
	}
	return 0;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("wrong number of arguments\n");
		return 0;
	}

	char *str = argv[1];
	char *start = str;
	char *p = str;
	for (; *p; p++)
		;
	p--;
	char *end;
	int biggest = 0;
	int c;
	char *pal;
	while (*start)
	{
		end = p;
		while (start < end)
		{
			end--;
			if (*start == *end)
				if ((c = check_palindrome(start)) > biggest)
				{
					biggest = c;
					pal = start;
				}
		}
		start++;
	}
	if (biggest > 0)
	{
		write(1, pal, biggest+1);
	}
	else
		write(1, argv[1], 1);
	write(1, "\n", 1);
}

int	ft_strlen(char *str)
{
	char	*p;

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
	write(1, str, p - str);
}
