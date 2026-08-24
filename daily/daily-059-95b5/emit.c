int	emit(const int *offset, const int *want, int n, int len)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < n)
	{
		if (offset[i] < len)
		{
			if (want[i] <= len - offset[i])
				total = total + want[i];
			else
				total = total + len - offset[i];
		}
		i++;
	}
	return (total);
}
