int	first_bad_step(const int *step_ok, int n)
{
	if (n > 0 && !step_ok[0])
		return (0);
	for (int i = 0; i < n; i++)
	{
		if (step_ok[i] == 0)
			return i;
	}
	if (n > 1 && !step_ok[n - 1])
		return (n - 1);
	return (-1);
}
