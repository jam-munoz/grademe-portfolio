void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort_array(int *tab, unsigned int size)
{
	for (unsigned int i = 1; i < size; i++)
	{
		int key = tab[i];
		int j = i - 1;
		while (j >= 0 && key < tab[j])
		{
			swap(&tab[j + 1], &tab[j]);
			j--;
		}
	}
}
