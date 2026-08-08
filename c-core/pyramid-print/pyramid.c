#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("wrong number of arguments\n");
		return 0;
	}
	int x, y;
	int size = atoi(argv[1]);
	for (y = 0; y < size; y++)
	{
		for (x = 0; x < y + size; x++)
		{
			if (x + y + 1 < size)
				ft_putchar(' ');
			else
				ft_putchar('#');
		}
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
