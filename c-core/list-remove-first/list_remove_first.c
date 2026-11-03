#include "list.h"
#include <stdlib.h>

// Unlinks the first node whose data matches ref (cmp returns 0) and frees the
// node and its data. *begin always ends up on the head of the list.
void	list_remove_first(ListNode **begin, void *ref, int (*cmp)(void *, void *))
{
	if (!begin || !(*begin) || !(*cmp))
		return;

	ListNode *p = (*begin)->next;
	ListNode *trail = *begin;

	while (p != NULL)
	{
		if ((*cmp)(ref, p->data) == 0)
		{
			trail->next = p->next;
			free(p->data);
			free(p);
			p = NULL;
			return;
		}
		p = p->next;
		trail = trail->next;
	}
	if ((*cmp)(ref, (*begin)->data) == 0)
	{
		p = *begin;
		*begin = (*begin)->next;
		free(p->data);
		free(p);
		p = NULL;
	}
}
