#include <stddef.h>
#include "list.h"

ListNode *merge(ListNode *l, ListNode *r, int (*cmp)(int, int))
{
	ListNode head;
	ListNode *tail = &head;
	head.next = NULL;

	while (l && r)
	{
		if ((*cmp)(l->data, r->data))
		{
			tail->next = l;
			l = l->next;
			tail = tail->next;
		}
		else
		{
			tail->next = r;
			r = r->next;
			tail = tail->next;
		}
	}
	if (l)
		tail->next = l;
	else
		tail->next = r;

	return head.next;
}

ListNode	*sort_list(ListNode *lst, int (*cmp)(int, int))
{
	if (!lst || !lst->next)
		return lst;

	ListNode *slow = lst;
	ListNode *fast = lst->next;
	ListNode *mid;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	mid = slow->next;
	slow->next = NULL;

	lst = sort_list(lst, cmp);
	mid = sort_list(mid, cmp);
	return merge(lst, mid, cmp);
}
