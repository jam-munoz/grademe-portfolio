int	index_value(const int *num, const int *den, int n)
{
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += (float)num[i] / den[i];
		if ((sum - (int)sum ) >= 0.5)
			sum += 0.5;
	}
	return (int)sum;
}
