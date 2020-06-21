/*
25. Reverse Nodes in k-Group


Given a linked list, reverse the nodes of a linked list k at a time and return its modified list. 

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
 Given this linked list: 1->2->3->4->5 

For k = 2, you should return: 2->1->4->3->5 

For k = 3, you should return: 3->2->1->4->5 

*/

#include <iostream>
#include <vector>

#include "ListNode.h"

using namespace std;


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == nullptr || head->next == nullptr || k < 2) {
            return head;
        }

		auto len = 0;
		for (ListNode *p = head; p != nullptr; p = p->next, ++len);
		//if (k > len) k %= len;
		if (k > len) {
            return head;
        }
		
		int nReverse = len / k;

		ListNode newHead(-1);

		ListNode *currSubHeadBeforeReverse = nullptr;
		ListNode *preSubTailAfterReverse = nullptr;
		ListNode *curr = head;
		for (auto i = 0; i < nReverse && curr != nullptr; ++i) {
			currSubHeadBeforeReverse = curr;

			// reverse sub list
			ListNode *pre = nullptr;
			ListNode *next = curr->next;
			curr->next = nullptr; // prevent endlessly
			for (auto j = 0; j < k-1 && next != nullptr; ++j) {
				pre = curr;
				curr = next;
				next = next->next;

				curr->next = pre; // reverse
			}
			if (currSubHeadBeforeReverse == head) {
                newHead.next = curr;
            } else {
                preSubTailAfterReverse->next = curr;
            }

			preSubTailAfterReverse = currSubHeadBeforeReverse;
			curr = next;
		}
		if (curr != nullptr) {
            preSubTailAfterReverse->next = curr;
        }

		return newHead.next;
	}
};


int main() {
	Solution obj;
	vector<int> test1 = { 1, 2, 3, 4, 5 };
	
	ListNode *head = construct_list(test1);
	print_list(obj.reverseKGroup(head, 1));
	
	head = construct_list(test1);
	print_list(obj.reverseKGroup(head, 2));

	head = construct_list(test1);
	print_list(obj.reverseKGroup(head, 3));

	head = construct_list(test1);
	print_list(obj.reverseKGroup(head, 4));

	head = construct_list(test1);
	print_list(obj.reverseKGroup(head, 5));

	head = construct_list(test1);
	print_list(obj.reverseKGroup(head, 6));

	head = construct_list(test1);
	print_list(obj.reverseKGroup(head, 7));

	vector<int> test2;
	head = construct_list(test2);
	print_list(obj.reverseKGroup(head, 1));

	return 0;
}
