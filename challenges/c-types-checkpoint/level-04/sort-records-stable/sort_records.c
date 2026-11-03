#include <stddef.h>

typedef struct s_record
{
	int	key;
	char	label;
}	record;

void swap(record *arr1, record *arr2);
// arr holds n records. Sort them by key, ascending, and leave records that
// share a key in the order they arrived.
void	sort_records(record *arr, size_t n)
{
	for (unsigned int i = 1; i < n; i++)
	{
		int key = arr[i].key;
		int j = i - 1;
		while (j >= 0 && key < arr[j].key)
		{
			swap(&arr[j + 1], &arr[j]);
			j--;
		}
	}
}

void swap(record *arr1, record *arr2)
{
	record temp;
	temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}