#include <unistd.h>
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	write(1, str, i);
	write(1, "\n", 1);
}
int	main(int argc, char **argv)
{
	if (argc != 1)
		for (argc-- ; argc > 0; argc--)
			ft_putstr(argv[argc]);
}