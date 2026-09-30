#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("wrong number of arguments\n");
		return 0;
	}
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int t;
	while (b != 0)
	{
		t = b;
		b = a % b;
		a = t;
	}
	printf("%d\n", a);
}
