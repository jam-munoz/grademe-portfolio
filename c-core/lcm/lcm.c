int gcd(int a, int b)
{
	int t;
	while (b != 0)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

unsigned int lcm(unsigned int a, unsigned int b)
{
	return (a * b) / gcd(a, b);
}
