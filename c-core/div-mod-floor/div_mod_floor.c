// Writes the quotient of a by b through q and the remainder through r,
// picking the pair where the remainder never goes negative.
void	div_mod_floor(int a, int b, int *q, int *r)
{
	if (a == 0)
	{
		*q = 0;
		*r = 0;
		return;
	}
	if (b == 0 || (a == -2147483647 - 1 && b == -1))
		return;
	if (a == b)
	{
		*q = 1;
		*r = 0;
		return;
	}

	*q = a / b;
	*r = a % b;
	if (*r < 0)
	{
		if (b > 0)
		{
			*r += b;
			*q -= 1;
		}
		else
		{
			*r -= b;
			*q += 1;
		}
	}

	return;
}
