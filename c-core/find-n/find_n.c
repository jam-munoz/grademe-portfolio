#include <unistd.h>
int	main(int argc, char **argv)
{
	if (argc != 2)
		return 0 * write(1, "wrong number of arguments\n", 26);
	for (int i = 0; argv[1][i]; i++)
		if (argv[1][i] == 'n')
			return 0 * write(1, "n\n", 2);
	write(1, "\n", 1);
}