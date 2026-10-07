#include <stdlib.h>
#include <unistd.h>

#define MAX_DISKS 64

typedef struct {
	int src;
	int aux;
	int dest;
	int a[MAX_DISKS];
	int b[MAX_DISKS];
	int c[MAX_DISKS];
	int size[3];
}	tower;

void	ft_putstr(char *str);
void	move_disk(int i, tower *t);
void	move_between(int a, int b, tower *t);

int	main(int argc, char **argv)
{
	tower			t;
	int				disk_count;
	unsigned long	moves;

	if (argc != 2)
	{
		ft_putstr("wrong number of arguments\n");
		return (0);
	}

	disk_count = atoi(argv[1]);
	if (disk_count < 1 || disk_count > MAX_DISKS)
		return (0);

	t.src = 0;
	if (disk_count % 2 == 0)
	{
		t.aux = 2;
		t.dest = 1;
	}
	else
	{
		t.aux = 1;
		t.dest = 2;
	}

	t.size[0] = disk_count;
	t.size[1] = 0;
	t.size[2] = 0;

	for (int i = 0; i < disk_count; i++)
		t.a[i] = disk_count - i;

	moves = (1UL << disk_count) - 1;

	for (unsigned long i = 1; i <= moves; i++)
		move_disk(i, &t);
}

void	ft_putstr(char *str)
{
	char	*p;

	p = str;
	while (*p)
		p++;
	write(STDOUT_FILENO, str, p - str);
}

void	move_disk(int i, tower *t)
{
	if (i % 3 == 1)
		move_between(t->src, t->dest, t);
	else if (i % 3 == 2)
		move_between(t->src, t->aux, t);
	else
		move_between(t->aux, t->dest, t);
}

void	move_between(int a, int b, tower *t)
{
	int	*stack_a;
	int	*stack_b;
	int	from;
	int	to;
	int	disk;

	stack_a = (a == 0) ? t->a : (a == 1) ? t->b : t->c;
	stack_b = (b == 0) ? t->a : (b == 1) ? t->b : t->c;

	if (t->size[b] == 0
		|| (t->size[a] > 0
			&& stack_a[t->size[a] - 1] < stack_b[t->size[b] - 1]))
	{
		from = a;
		to = b;
		disk = stack_a[t->size[a] - 1];
		stack_b[t->size[b]++] = disk;
		t->size[a]--;
	}
	else
	{
		from = b;
		to = a;
		disk = stack_b[t->size[b] - 1];
		stack_a[t->size[a]++] = disk;
		t->size[b]--;
	}

	if (from == 0)
		ft_putstr("A ");
	else if (from == 1)
		ft_putstr("B ");
	else
		ft_putstr("C ");

	if (to == 0)
		ft_putstr("A\n");
	else if (to == 1)
		ft_putstr("B\n");
	else
		ft_putstr("C\n");
}
