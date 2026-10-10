typedef struct rational
{
	int	num;
	int	den;
} rational;

long ft_gcd(long a, long b);
// rational_reduce divides num and den by their gcd and moves the sign onto num,
// so den comes out strictly positive.
void	rational_reduce(rational *r)
{
	int gcd = ft_gcd(r->num, r->den);
	r->num /= gcd;
	r->den /= gcd;
	if (r->den < 0)
	{
		r->den = -r->den;
		r->num = -r->num;
	}
}

long ft_gcd(long a, long b) 
{
	long r;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
