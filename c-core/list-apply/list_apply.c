#include "list.h"
#include <stddef.h>

void	list_apply(ListNode *list, void (*f)(void *))
{
	while (list)
	{
		(*f)(list->data);
		list = list->next;
	}
}
