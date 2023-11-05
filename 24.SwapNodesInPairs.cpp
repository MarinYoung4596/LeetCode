/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
    Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (nullptr == head) {
            return head;
        }
        ListNode saved_head(-1);
        saved_head.next = head;

        ListNode* pre = &saved_head;
        ListNode* p = head,
        ListNode* q = p->next;

        while (p && q) {
            // reverse
            pre->next = q;
            p->next = q->next;
            q->next = p;

            // scan
            pre = p;
            if (nullptr == pre->next) {
                p = q = nullptr;
                break;
            }
            p = pre->next;
            q = p->next;
        }
        return saved_head.next;
    }
};