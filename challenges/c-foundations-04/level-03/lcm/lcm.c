unsigned int lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return 0;
	int lcm, other;
	if (a < b)
	{
		lcm = a;
		other = b;
	}
	else
	{
		lcm = b;
		other = a;
	}
	int base = lcm;
	while (lcm % other != 0)
	{
		lcm += base;
	}
	return lcm;
}
