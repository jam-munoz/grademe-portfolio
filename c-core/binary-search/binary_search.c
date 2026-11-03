#include <stddef.h>

// binary_search returns the smallest index whose value is key, or -1 when the
// sequence holds none. at(i) is the only way to read it, and costs one probe.
long	binary_search(size_t n, int key, int (*at)(size_t))
{
	long start = 0;
	long end = (long)n;
	while (start < end)
	{
		long mid = start + (end - start) / 2;
		int value = (*at)(mid);
		if (key > value)
			start = mid + 1;
		else
			end = mid;
	}
	if (start < (long)n && (*at)(start) == key)
		return start;
	return -1;
}
