int	apply_drop(int *out, const int *base, int n, int drop)
{	int j = 0;
	for (int i = 0; i < n; i++)
	{
		out[i] = base[i] - drop;
		if (out[i] < 0)
		{
			out[i] = 0;
			j++;
		}
	}
	return j;
}
