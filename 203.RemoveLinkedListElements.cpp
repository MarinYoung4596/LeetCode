/*
203. Removed Linked List Elements
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

#include "ListNode.h"
#include <iostream>


ListNode* removeElements(ListNode* head, int val) {
	if (head == nullptr) {
        return nullptr;
    }

	ListNode *pre = head;
	ListNode *p = head;
	for (; p != nullptr; ) {
		if (val != p->val) {
			pre = p;
			p = p->next;
			continue;
		}
		if (p == head) {		// Head
			ListNode *tmp = head;
			head = head->next;
			p = pre = head;
			delete tmp;
			continue;
		}
		if (p->next == nullptr) {	// Tail
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

int main(int argc, char **argv) {
	int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	ListNode *p = new ListNode(A[0]);
	ListNode *head = p;
	for (int i = 1; i < 10; i++) {
		p->next = new ListNode(A[i]);
		p = p->next;
	}
	print_list(head);

	p = removeElements(head, 5);	// Middle
	print_list(p);

	p = removeElements(p, 1);		// Head
	print_list(p);

	p = removeElements(p, 0);		// Tail
	print_list(p);

	ListNode *singleNode = new ListNode(100);
	p = removeElements(singleNode, 100);	// SingleNode
	print_list(p);

	return 0;
}
