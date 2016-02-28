/*
143. Reorder List.
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

#include <vector>
#include <iostream>
#include <algorithm>

#include "ListNode.h"

using namespace std;
// Ordinary List: 1->2->3->4->5->6->7
// Reordered List:1->(7)->2->(6)->3->(5)->4
void reorderList(ListNode* head)
{
	vector<int> v;
	for (ListNode *p = head; p != nullptr; p = p->next)
		v.push_back(p->val);

	const int len = v.size();
	if (len < 3) return;
	int sigma = len % 2 == 1 ? ((len + 1) / 2 - 1) : (len / 2 - 1);
	ListNode *p = head;
	for (int i = 0; i < sigma; i++)
	{
		ListNode *tmp = new ListNode(v[len - 1 - i]);
		tmp->next = p->next;
		p->next = tmp;
		p = p->next->next;
	}
	if (len % 2 == 1)
		p->next = nullptr;
	else
		p->next->next = nullptr;
}

int main()
{
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
	ListNode *head = new ListNode(v[0]);
	ListNode *p = head;
	for (auto i = next(v.begin()); i != v.end(); i++, p = p->next)
		p->next = new ListNode(*i);

	printListNode(head);
	reorderList(head);
	printListNode(head);

	system("pause");
	return 0;
}
