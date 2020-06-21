/*
Remove Duplicates from Sorted List II

Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/
#include <vector>
#include "ListNode.h"

ListNode* deleteDuplicates(ListNode* head)
{
	if (head == nullptr)
		return nullptr;

	ListNode savedhead(-1);
	savedhead.next = head;

	ListNode *pre = &savedhead, *curr = &savedhead;
	ListNode *toBeDeleted = nullptr;

	curr = curr->next;
	for (; curr != nullptr; )
	{
		if (curr->next != nullptr && curr->val == curr->next->val)
			toBeDeleted = curr;

		if (toBeDeleted != nullptr && curr->val == toBeDeleted->val)
		{
			pre->next = curr->next;
			curr = curr->next;
			continue;
		}
		pre = pre->next;
		curr = curr->next;
	}
	return savedhead.next;
}


int main()
{
	// test case:
	// 1, 1, 1, 2, 3
	// 1, 2, 3, 3, 4, 4, 5
	vector<int> list({ 1, 1, 1, 2, 3 });
	ListNode *p = new ListNode(list[0]);
	ListNode *head = p;
	for (auto i = list.begin() + 1; i != list.end(); ++i)
	{
		p->next = new ListNode(*i);
		p = p->next;
	}
		
	head = deleteDuplicates(head);
	while (head != nullptr)
		std::cout << head->val << '\t';
	std::cout << std::endl;

	system("pause");
	return 0;
}