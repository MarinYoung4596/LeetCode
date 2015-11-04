/*
142. Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/
#include "ListNode.h"

ListNode *detectCycle(ListNode *head) 
{
	ListNode *metting_node = meetingNode(head);
	if (metting_node == nullptr)
		return nullptr;

	// get the number of nodes in loop
	int nodesInloop = 1;
	for (ListNode *pCurr = metting_node; pCurr->next != metting_node; pCurr = pCurr->next)
		++nodesInloop;

	ListNode *pNode_1 = head;
	for (int i = 0; i < nodesInloop; ++i)
		pNode_1 = pNode_1->next;

	ListNode *pNode_2 = head;
	for (; pNode_1 != pNode_2; pNode_1 = pNode_1->next, pNode_2 = pNode_2->next);
	return pNode_1;
}

// Given a linked list, determine if it has a cycle in it. 
// if yes, return the meeting node, else return nullptr.
// Same as 141. Linked list cycle
ListNode *meetingNode(ListNode *head)
{
	ListNode *slow = head, *fast = head;
	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return fast;	
	}
	return nullptr;
}
