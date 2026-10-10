#include <stddef.h>

// copy_frame copies at most announced bytes of src into dst, never writes past
// cap, always terminates dst, and returns 0 only for a complete copy.
int	copy_frame(char *dst, size_t cap, const char *src, size_t announced)
{
	size_t	i;

	if (cap == 0)
		return -1;
	i = 0;
	while (src[i] && i < announced && i < cap - 1 )
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	if (i == announced)
		return (0);
	else
		return -1;
}
