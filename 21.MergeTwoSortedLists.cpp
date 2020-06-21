/*
21	Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
*/
#include "ListNode.h"

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;

	ListNode head(0);
	ListNode *pCurr = &head;

	for (; l1 != NULL && l2 != NULL; pCurr = pCurr->next)
	{
		if (l1->val < l2->val)
		{
			pCurr->next = l1;
			l1 = l1->next;
		}
		else if (l1->val > l2->val)
		{
			pCurr->next = l2;
			l2 = l2->next;
		}
		else
		{
			pCurr->next = l1;
			pCurr = pCurr->next;
			pCurr->next = l2;

			l1 = l1->next;
			l2 = l2->next;
		}
	}
	if (l1 != NULL)
		pCurr->next = l1;
	else
		pCurr->next = l2;

	return head.next;
}
