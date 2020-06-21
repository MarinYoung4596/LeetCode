/*
61. Rotate List
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

#include "ListNode.h"
#include <vector>

// Time Complexity : O(N), Space Complexity : O(1)
ListNode* rotateRight(ListNode* head, int k) {
	if (!head || !k) {
        return head;	// !head && k == 0
    }

	ListNode *pre = head;
    ListNode *pLast = head;

	int len = 0;
	for (ListNode *p = head; p != nullptr; p = p->next, len++);
	
    k %= len;	// for the case that k > len
	if (!k) {
        return head;	// k % len == 0 ( including: k == len)
    }

	for (int i = 0; i < k; i++) {
		pLast = pLast->next;
    }

	while (pLast->next != nullptr) {
		pre = pre->next;
		pLast = pLast->next;
	}
	ListNode *tmp = head;
	head = pre->next;
	pre->next = nullptr;
	pLast->next = tmp;
	return head;
}

int main() {
	vector<int> v = { 1, 2, 3, 4, 5, 6 };
	ListNode *head = new ListNode(v[0]);
	ListNode *p = head;
	for (auto i = next(v.begin()); i != v.end(); i++, p = p->next) {
		p->next = new ListNode(*i);
    }

	head = rotateRight(head, 3);
	print_list(head);

	system("pause");
	return 0;
}
