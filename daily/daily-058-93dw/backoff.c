int	backoff(const int *ok, int n)
{
	int wait = 1;

	for (int i = 0; i < n; i++)
	{
		if (ok[i] == 0)
		{
			wait *= 2;
			if (wait > 32)
				wait = 32;
		}
		else if (ok[i] == 1)
			wait = 1;
	}
	return wait;
}
