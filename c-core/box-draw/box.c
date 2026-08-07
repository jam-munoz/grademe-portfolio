#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
// argv[1] is the width, argv[2] the height. Draw the frame of that rectangle:
// '+' corners, '-' on top and bottom, '|' on the sides, spaces inside.
int	main(int argc, char **argv)
{
	if (argc != 3)
		return 0 * write(1, "wrong number of arguments\n", 26);

	int y = atoi(argv[2]);
	int x = atoi(argv[1]);

	if (x < 1 || y < 1)
		return 0;
		
	int i, j;

	for (i = 0; i < y; i++)
	{
		for (j = 0; j < x; j++)
		{
			if ((i == 0 && (j == 0 || j == x - 1)) || (i == y - 1 && (j == 0 || j == x - 1)))
				ft_putchar('+');
			else if (i == 0 || i == y - 1)
				ft_putchar('-');
			else if (j == 0 || j == x - 1)
				ft_putchar('|');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
