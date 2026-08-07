#include <unistd.h>
int	main(int argc, char **argv)
{
	if (argc == 1)
		return 0 * write(1, "wrong number of arguments\n", 26);
	int len = 0;
	for (; argv[argc - 1][len]; len++) ;
	write (1, argv[argc - 1], len);
	write (1, "\n", 1);
}