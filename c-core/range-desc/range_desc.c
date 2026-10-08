#include <stdlib.h>

int *range_desc(int from, int to)
{
	int temp = 0;
	if (from > to)
	{
		temp = from;
		from = to;
		to = temp;
	}
	int *arr = malloc((to - from + 1) * sizeof(int));
	if (!temp)
	{
		for (int i = to, j = 0; i >= from; i--, j++)
		{
			arr[j] = i;
		}
	}
	else
	{
		for (int i = from, j = 0; i <= to; i++, j++)
		{
			arr[j] = i;
		}
	}
	return arr;
}
