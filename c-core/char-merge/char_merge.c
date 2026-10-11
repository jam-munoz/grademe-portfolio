#include <stdbool.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(STDOUT_FILENO, "wrong number of arguments\n", 26);
		return 0;
	}
	char str[4096];
	bool seen[255] = { false };
	int idx = 0;
	for (int i = 0; argv[2][i]; i++)
	{
		if (!seen[(unsigned char)argv[2][i]])
		{
			str[idx++] = argv[2][i];
			seen[(unsigned char)argv[2][i]] = true;
		}
	}
	for (int i = 0; argv[1][i]; i++)
	{
		if (!seen[(unsigned char)argv[1][i]])
		{
			str[idx++] = argv[1][i];
			seen[(unsigned char)argv[1][i]] = true;
		}
	}
	str[idx] = '\n';
	write(STDOUT_FILENO, str, idx + 1);
}
