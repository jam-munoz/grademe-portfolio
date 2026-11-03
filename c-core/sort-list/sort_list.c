#include "list.h"

static ListNode *merge(ListNode *a, ListNode *b, int (*cmp)(int, int))
{
	ListNode head;
	ListNode *tail = &head;
	head.next = (void *)0;

	while (a && b)
	{
		if ((*cmp)(a->data, b->data) != 0)
		{
			tail->next = a;
			a = a->next;
			tail = tail->next;
		}
		else
		{
			tail->next = b;
			b = b->next;
			tail = tail->next;
		}
	}
	if (a)
		tail->next = a;
	else
		tail->next = b;
	return head.next;
}

ListNode	*sort_list(ListNode *lst, int (*cmp)(int, int))
{
	if (!lst || !lst->next)
    	return lst;

	ListNode *slow = lst, *fast = lst->next, *mid;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	mid = slow->next;
	slow->next = (void *)0;
	lst = sort_list(lst, cmp);
	mid = sort_list(mid, cmp);
	return merge(lst, mid, cmp);
}
