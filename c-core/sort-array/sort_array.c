void	ft_swap(int *a, int *b);

void sort_array(int *tab, unsigned int size)
{
	for (unsigned int i = 1; i < size; i++)
	{
		int key = tab[i];
		for (int j = i - 1; key < tab[j] && j >= 0; j--)
		{
			ft_swap(&tab[j], &tab[j + 1]);
		}
	}
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
