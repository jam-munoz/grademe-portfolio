#include <stdbool.h>
#include <unistd.h>

int	main(int argc, char **argv)
{	
	if (argc != 3)
	{
		write(STDOUT_FILENO, "wrong number of arguments\n", 26);
		return 0;
	}
	int i, j = 0, k = 0;
	char str[4096];
	bool seen[255] = { false };
	for (i = 0; argv[2][i]; i++)
	{
		for (j = 0; argv[1][j]; j++)
		{
			if (argv[2][i] == argv[1][j] && !seen[(unsigned char)argv[2][i]])
			{
				str[k++] = argv[2][i];
				seen[(unsigned char)argv[2][i]] = true;
				break;
			}
		}
	}
	str[k] = '\n';
	write(STDOUT_FILENO, str, k + 1);
}
