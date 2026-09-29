#include <unistd.h>

void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		ft_putstr("wrong number of arguments\n");
		return 0;
	} 
	if (argv[2][1] || argv[3][1])
	{
		ft_putstr("\n");
		return 0;
	}
	char *str = argv[1];
	while (*str)
		str++;
	while (str >= argv[1])
	{
		if (*str == *argv[2])
		{
			*str = *argv[3];
			break;
		}
		str--;
	}
	ft_putstr(argv[1]);
	ft_putstr("\n");
}

void	ft_putstr(char *str)
{
	char	*p;

	p = str;
	while (*p != '\0')
		p++;
	write(1, str, p - str);
}
