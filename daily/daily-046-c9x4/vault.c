int	drain(int balance, const int *request, int n)
{
	int	i;
	int	paid;

	i = 0;
	paid = 0;
	while (i < n)
	{
		if (request[i] <= balance)
		{
			paid = paid + request[i];
			balance -= request[i];
		}
		i++;
	}
	return (paid);
}
