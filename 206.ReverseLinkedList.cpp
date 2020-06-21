/*
206. Reverse Linked List 
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// First Solution: iterative solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (nullptr == head || nullptr == head->next) {
			return head;
		}
		auto pre = head;
		auto cur = pre->next;
        pre->next = nullptr; /// important, without which list will be endlessly
		while (cur != nullptr) {
			auto next = cur->next;

			cur->next = pre;
			pre = cur;
			cur = next;
		}
        return pre;
    }
};

// Second Solution: recursive
ListNode* reverse_list_recursive(ListNode* head) {
    if (head->next == nullptr) {
        return head;
    }
    auto p = reverse_list_recursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}
