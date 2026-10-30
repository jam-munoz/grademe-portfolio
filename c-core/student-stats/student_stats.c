#include <stddef.h>

typedef struct s_student
{
	const char	*name;
	int		score;
} student;

typedef struct s_stats
{
	int		min;
	int		max;
	int		mean;
	const char	*best;
} stats;

// out receives min, max, the mean truncated toward zero, and the name of the
// top scorer. With n of 0, the three numbers are 0 and best is NULL.
void	student_stats(const student *a, size_t n, stats *out)
{
	if (n == 0)
	{
		out->min = 0;
		out->max = 0;
		out->mean = 0;
		out->best = NULL;
		return;
	}
	long avg = a[0].score;
	out->min = a[0].score;
	out->max = a[0].score;
	out->best = a[0].name;

	for (unsigned int i = 1; i < n; i++)
	{
		if (a[i].score < out->min)
		{
			out->min = a[i].score;
		}
		else if (a[i].score > out->max)
		{
			out->max = a[i].score;
			out->best = a[i].name;
		}
		avg += a[i].score;
	}
	out->mean = (double)avg / n;
}
