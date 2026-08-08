typedef struct point
{
	int	x;
	int	y;
} point;

// point_distance2 returns the squared distance between a and b, widened to long
// before any subtraction and before any multiplication.
long	point_distance2(point a, point b)
{
	long distance = (((long)a.x - b.x) * ((long)a.x - b.x) + ((long)a.y - b.y) * ((long)a.y - b.y));
	return distance;
}
