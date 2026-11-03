#include <stdlib.h>
#include <stddef.h>

// A stack of int with no size limit: the last value pushed is the first one
// popped. The fields of struct s_stack are yours to choose.
typedef struct s_stack	Stack;

struct s_stack
{
	size_t	size;
	int		stack[5000];
};

Stack	*stack_new(void)
{
	Stack *new = malloc(sizeof(Stack));
	if (new == NULL)
		return NULL;
	new->size = 0;
	return new;
}

int	stack_push(Stack *s, int value)
{
	s->stack[s->size] = value;
	s->size++;
	return 0;
}

int	stack_pop(Stack *s, int *out)
{
	if (s->size == 0)
		return 0;
	s->size--;
	*out = s->stack[s->size];
	return 1;
}

size_t	stack_size(const Stack *s)
{
	return s->size;
}

void	stack_free(Stack *s)
{
	if (s == NULL)
		return;
	free(s);
	s = NULL;
}
