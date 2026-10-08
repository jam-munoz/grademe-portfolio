typedef struct Point
{
	int x;
	int y;
} Point;

void	flood_util(char **tab, Point size, Point begin, char target)
{
	Point next;
	if (begin.x >= size.x || begin.y >= size.y || begin.x < 0 || begin.y < 0)
		return;
	if (tab[begin.y][begin.x] != target)
		return;
	tab[begin.y][begin.x] = 'F';
	next.x = begin.x + 1;
	next.y = begin.y;
	flood_util(tab, size, next, target);
	next.x = begin.x - 1;
	next.y = begin.y;
	flood_util(tab, size, next, target);
	next.x = begin.x;
	next.y = begin.y + 1;
	flood_util(tab, size, next, target);
	next.x = begin.x;
	next.y = begin.y - 1;
	flood_util(tab, size, next, target);
}

void	flood_fill(char **tab, Point size, Point begin)
{
	flood_util(tab, size, begin, tab[begin.y][begin.x]);
}
