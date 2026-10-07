#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(STDOUT_FILENO, "wrong number of arguments\n", 26);
		return 0;
	}
	char *str = argv[1];
	int i;
	for (i = 0; str[i]; i++)
	{
		if (('a' <= str[i] && str[i] <= 'm') || ('A' <= str[i] && str[i] <= 'M'))
			str[i] = str[i] + 13;
		else if (('m' < str[i] && str[i] <= 'z') || ('M' < str[i] && str[i] <= 'Z'))
			str[i] = str[i] - 13;
	}
	str[i] = '\n';
	write(STDOUT_FILENO, str, i + 1);
}
