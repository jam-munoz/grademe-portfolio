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
	int temp;
	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	if (b != 0)
	{
		while (b != 0)
		{
			temp = a % b;
			a = b;
			b = temp;
		}
	}
	printf("%d\n", a);
}
