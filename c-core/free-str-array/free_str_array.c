#include <stdlib.h>
#include <stddef.h>

// Frees every string of the NULL-terminated arr, then arr itself.
// Returns how many strings were freed.
size_t	free_str_array(char **arr)
{
	int i;
	if (arr == NULL)
		return 0;
	for (i = 0; arr[i] != NULL; i++)
		free(arr[i]);
	free(arr);
	return i;
}
