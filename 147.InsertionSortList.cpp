/*
147. Insertion Sort List
Sort a linked list using insertion sort
*/
#include "ListNode.h"

class Solution
{
public:
	ListNode* insertionSortList(ListNode* head) 
	{
		if (!head) return head;
		for (ListNode *p = head->next; p != nullptr; p = p->next)
		{
			for (ListNode *q = head; q != p; q = q->next)
			{
				if (q->val > p->val)
					swap(q->val, p->val);
			}
		}
		return head;
	}
};
