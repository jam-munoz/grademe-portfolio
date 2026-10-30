#include "list.h"
#include <stdlib.h>

void	list_filter(ListNode **begin, void *ref, int (*cmp)(void *, void *))
{
	if (begin == NULL || *begin == NULL || (*cmp) == NULL || ref == NULL)
		return;
	
	ListNode *p = *begin;
	ListNode *prev = p;
	ListNode *rmv;
		p = p->next;
	while (p)
	{
		if ((*cmp)(p->data, ref) == 0)
		{
			rmv = p;
			p = p->next;
			prev->next = p;
			free(rmv);
			rmv = NULL;
		}
		else
		{
			prev = p;
			p = p->next;
		}
	}
	if (((*cmp)((*begin)->data, ref) == 0))
	{
		rmv = *begin;
		*begin = (*begin)->next;
		free(rmv);
		rmv = NULL;
	}
}
