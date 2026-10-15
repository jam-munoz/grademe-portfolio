int	pick_power_source(const int *live, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (live[i])
			return i;
	}
	return (-1);
}
