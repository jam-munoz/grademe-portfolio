#include <stdlib.h>

int *range_desc(int min, int max)
{
	int size = max - min;
	if (size < 0)
		size = -size;
	int *range = malloc((size + 1) * sizeof(int));
	for (int i = 0; max >= min; max--, i++)
	{
		range[i] = max;
	}
	return range;
}
