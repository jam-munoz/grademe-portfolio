#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
// Each argument is one value. Print its bar: that many '#', then a newline.
// A value that is zero or negative gives an empty line, newline included.
int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr("wrong number of arguments\n");
	}

	int n, i, j;
	for (i = 1; i < argc; i++)
	{
		n = atoi(argv[i]);
		for (j = 0; j < n; j++)
			ft_putchar('#');
		ft_putchar('\n');
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	write(1, str, i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}