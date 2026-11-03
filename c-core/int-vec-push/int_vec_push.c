#include <stdlib.h>
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);
// Appends value to the growable array described by data, len and cap.
// Returns 0 on success, -1 if the array could not grow.
int	int_vec_push(int **data, size_t *len, size_t *cap, int value)
{
	unsigned int new_cap;
	if (*len < *cap)
	{
		(*data)[*len] = value;
		(*len)++;
		return 0;
	}
	if (*cap == 0)
		new_cap = 4;
	else
		new_cap = *cap * 2;
	int *new = malloc(new_cap * sizeof(int));
	if (new == NULL)
		return -1;
	ft_memcpy(new, *data, *len * sizeof(int));
	free(*data);
	new[*len] = value;
	(*len)++;
	*cap = new_cap;
	*data = new;
	return 0;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}
