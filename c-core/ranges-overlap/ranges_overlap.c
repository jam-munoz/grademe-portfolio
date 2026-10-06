#include <stddef.h>

// Both slices come from the same array, so their addresses are comparable.
// Touching is not overlapping, and an empty slice covers no byte at all.
int	ranges_overlap(const void *a, size_t na, const void *b, size_t nb)
{
	if (na == 0 || nb == 0)
		return 0;
	for (size_t i = 0; i < na; i++)
	{
		if (b <= a + i && a + i + 1 <= b + nb)
			return 1;
	}
	
	return (0);
}
