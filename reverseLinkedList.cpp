/*
206. Reverse Linked List 
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/
#include <iostream>
#include "ListNode.h"

using namespace std;

// First Solution: iterative solution
ListNode* reverseList(ListNode* head)
{
	if (head == nullptr) return head;

	ListNode *p = head,
		*q = p->next;
	p->next = nullptr;	// THAT'S VERY IMPORTANT! WITHOUT WHICH THE LIST WOULD BE ENDLESSLY.
	while (q != nullptr)
	{
		ListNode *pre = p;
		p = q;
		q = q->next;

		p->next = pre;
	}
	return p;
}

// Second Solution:
// To be continued...

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
	head = reverseList(head);
	printListNode(head);

	system("pause");
	return 0;
}
