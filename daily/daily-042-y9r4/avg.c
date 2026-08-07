int	average(const int *a, int n)
{
	if (!a || n < 1)
		return 0;
	int	i;
	int	sum;

	sum = 0;
	i = 0;
	while (i < n)
	{
		sum = sum + a[i];
		i++;
	}
	return (sum / n);
}
