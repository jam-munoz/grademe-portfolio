#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		printf("wrong number of arguments\n");
		return 0;
	}
	char op = *argv[2];
	int x = atoi(argv[1]);
	int y = atoi(argv[3]);
	int res;
	switch (op)
	{
		case '+': res = x + y;
			break;
		case '-': res = x - y;
			break;
		case '*': res = x * y;
			break;
		case '/': res = x / y;
			break;
		case '%': res = x % y;
			break;
	}
	printf("%d\n", res);
}
