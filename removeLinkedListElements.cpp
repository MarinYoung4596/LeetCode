/*
203. Removed Linked List Elements
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

#include "ListNode.h"
#include <iostream>

void printListNode(ListNode *head)
{
	if (head == nullptr)
		return;
	for (; head != nullptr; head = head->next)
		std::cout << head->val << '\t';
	std::cout << std::endl;
}

ListNode* removeElements(ListNode* head, int val)
{
	if (head == nullptr) return nullptr;

	ListNode *pre = head,
		*p = head;
	for (; p != nullptr; )
	{
		if (val != p->val)
		{
			pre = p;
			p = p->next;
			continue;
		}
		// else
		if (p == head)			// Head
		{
			ListNode *tmp = head;
			head = head->next;
			p = pre = head;
			delete tmp;
			continue;
		}
		if (p->next == nullptr)	// Tail
		{
			pre->next = nullptr;
			delete p;
			break;
		}
		// Middle
		ListNode *tmp = p;
		pre->next = p->next;
		p = p->next;
		delete tmp;
	}
	return head;
}

int main(int argv, char **argc)
{
	int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	ListNode *p = new ListNode(A[0]),
		*head = p;
	for (int i = 1; i < 10; i++)
	{
		p->next = new ListNode(A[i]);
		p = p->next;
	}
	printListNode(head);

	p = removeElements(head, 5);	// Middle
	printListNode(p);

	p = removeElements(p, 1);		// Head
	printListNode(p);

	p = removeElements(p, 0);		// Tail
	printListNode(p);

	ListNode *singleNode = new ListNode(100);
	p = removeElements(singleNode, 100);	// SingleNode
	printListNode(p);

	return 0;
}
