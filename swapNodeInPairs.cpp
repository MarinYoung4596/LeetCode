/*
24. Swap Node in Pairs
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/
#include <iostream>
#include "ListNode.h"

using namespace std;

ListNode* swapPairs(ListNode* head)
{
	if (!head) return head;
	ListNode savehead(-1);
	savehead.next = head;
	
	ListNode *pre = &savehead,
		*p = head,
		*q = p->next;

	while (p && q)
	{
		// reverse
		pre->next = q;
		p->next = q->next;
		q->next = p;

		// scan
		pre = p;
		if (!pre->next) 
		{
			p = q = nullptr;
			break;
		}
		p = pre->next;
		q = p->next;
	}
	return savehead.next;
}


int main()
{
	int a[] = { 1, 2 };
	ListNode *head = new ListNode(a[0]);
	ListNode *p = head;
	for (int i = 1; i < sizeof(a) / sizeof(int); i++)
	{
		p->next = new ListNode(a[i]);
		p = p->next;
	}
	head = swapPairs(head);
	printListNode(head);

	system("pause");
	return 0;
}
