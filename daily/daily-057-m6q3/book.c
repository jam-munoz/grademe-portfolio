int	insert_order(int *book, int n, int price)
{
	int i = 0;
	int temp;
	int next;
	int index;

	for (; i < n; i++)
	{
		if (price > book[i])
			break;
	}
	index = i;
	temp = book[i];
	book[i++] = price;
	for (; i <= n; i++)
	{
		next = book[i];
		book[i] = temp;
		temp = next;
	}
	return index;
}
