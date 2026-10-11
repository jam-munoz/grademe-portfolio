#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(STDOUT_FILENO, "wrong number of arguments\n", 26);
		return 0;
	}
	char *sub = argv[1];
	char *str = argv[2];

	while (*str)
	{
		if (*sub == *str)
		{
			sub++;
			str++;
		}
		else
			str++;
	}
	if (*sub == '\0')
		write(STDOUT_FILENO, "yes\n", 4);
	else
		write(STDOUT_FILENO, "no\n", 3);
}
