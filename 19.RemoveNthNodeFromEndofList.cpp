/*
19.	Remove Nth Node From End of List
Given a linked list, remove the nth node from the end of list and return its head.
For example,
Given linked list : 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note :
	 Given n will always be valid.
	 Try to do this in one pass.
*/
#include "ListNode.h"

ListNode *removeNthFromEnd(ListNode *head, int n)
{
	if (head == NULL || n <= 0)
		return NULL;

	// for the case that there are only one element in *head
	// and when we delete *head, then no node to return.
	// e.g. ({1}, 1) --> {}
	ListNode saveHead(0);
	saveHead.next = head;

	// point to the address of saveHead
	ListNode *pre = &saveHead, *pCurr = &saveHead;

	// make n-1 nodes included between *pre and *pCurr
	// named, pre->1->2->3->...->n-1->pCurr
	//			   1  2  3       n-1   n
	// when pCurr == Tail, then pre->next (named, node 1) is the node to be deleted.
	for (int i = 0; i < n; i++)
	{
		// if pCurr == NULL, means n is larger than the length of ListNode *head
		if (pCurr == NULL)
			return NULL;
		pCurr = pCurr->next;
	}
	// traversal until pCurr to the end of the list
	while (pCurr->next != NULL)
	{
		pre = pre->next;
		pCurr = pCurr->next;
	}
	// delete the Nth node from the end
	ListNode *tmp = pre->next;
	pre->next = pre->next->next;
	delete tmp;

	return saveHead.next;
}
