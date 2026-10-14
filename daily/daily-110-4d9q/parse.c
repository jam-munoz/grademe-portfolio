#include <stddef.h>

int	bytes_scanned(const int *len, int n)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			sum += len[j];
		}
	}
	return sum;
}
