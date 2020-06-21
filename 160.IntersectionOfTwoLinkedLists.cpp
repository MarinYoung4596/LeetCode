/*
160. Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.
For example, the following two linked lists :
A : a1 → a2
	↘
	c1 → c2 → c3
	↗
B : b1 → b2 → b3
	begin to intersect at node c1.

Notes :
	  If the two linked lists have no intersection at all, return null.
	  The linked lists must retain their original structure after the function returns.
	  You may assume there are no cycles anywhere in the entire linked structure.
	  Your code should preferably run in O(n) time and use only O(1) memory.
Solutions:
	If they are intersect at node cx; then their tail will be the same;	

*/
#include "ListNode.h"

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	if (headA == NULL || headB == NULL)
		return NULL;

	ListNode *pCurrA = headA;
	int lenA = 1;
	while (pCurrA->next != NULL)
	{
		pCurrA = pCurrA->next;
		lenA++;
	}

	ListNode *pCurrB = headB;
	int lenB = 1;
	while (pCurrB->next != NULL)
	{
		pCurrB = pCurrB->next;
		lenB++;
	}
	if (pCurrA != pCurrB) // if pTailA != pTailB
		return NULL;

	// else, they have the same tail, named pTailA == pTailB
	int sub = lenA - lenB;
	if (sub > 0)			// lenA > lenB
	{
		for (; sub; --sub)
			headA = headA->next;
	}
	else if (sub < 0)		// lenA < lenB
	{
		for (; sub < 0; ++sub) // attention: sub<0; in case that sub = -1, so that !sub is wrong
			headB = headB->next;
	}
	// headA == headB or at the same position, go together
	for (; headA != headB; headA = headA->next, headB = headB->next);
	return headA;
}
