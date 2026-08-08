#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int	ft_strlen(char *str);
void	ft_swap(char *a, char *b);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("wrong number of arguments\n");
		return 0;
	}
	int i, len = ft_strlen(argv[1]) - 1;
	char *str = argv[1];

	for (i = 0; i < len; i++, len--)
		ft_swap(&str[i], &str[len]);
	ft_putstr(str);
	ft_putchar('\n');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

