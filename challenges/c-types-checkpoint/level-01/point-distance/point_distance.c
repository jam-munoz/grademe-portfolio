// point is provided as is. Keep both fields and their order.
typedef struct point
{
	int	x;
	int	y;
} point;

// point_distance2 returns the squared distance between a and b, widened to long
// before any subtraction and before any multiplication.
long	point_distance2(point a, point b)
{
	long x = (long)a.x - b.x;
	x *= x;
	long y = (long)a.y - b.y;
	y *= y;
	return x + y;
}

