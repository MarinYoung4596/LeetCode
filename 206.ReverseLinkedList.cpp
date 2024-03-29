/*
Reverse a singly linked list.

Hint:
    A linked list can be reversed either iteratively or recursively. Could you implement both?
*/


// First Solution: iterative solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
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
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto p = reverse_list_recursive(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};