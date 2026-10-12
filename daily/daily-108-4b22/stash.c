#include <stdbool.h>

int	unique_items(int *out, const int *ids, int n)
{
	bool seen[1024] = { false };
	int idx = 0;

	for (int i = 0; i < n; i++)
	{
		if (!seen[ids[i]])
		{
			seen[ids[i]] = true;
			out[idx++] = ids[i];
		}
	}
	return idx;
}
