#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("wrong number of arguments\n");
		return 0;
	}
	int n = atoi(argv[1]);
	if (n == 1)
	{
		printf("1\n");
		return 0;
	}
	int i;
	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			printf("%d*", i);
			n /= i;
			i--;
		}
	}
	if (i >= n)
		printf("%d\n", i);
}