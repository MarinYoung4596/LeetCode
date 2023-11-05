/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
    Given 1->2->3->4->5->NULL and k = 2,
    return 4->5->1->2->3->NULL.
*/

#include "ListNode.h"
#include <vector>

// Time Complexity : O(N), Space Complexity : O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !k) {
            return head;    // !head && k == 0
        }
        ListNode *pre = head;
        ListNode *p_last = head;
        int len = 0;
        for (ListNode *p = head; p != nullptr; p = p->next, len++);

        k %= len;    // for the case that k > len
        if (!k) {
            return head;    // k % len == 0 ( including: k == len)
        }
        for (int i = 0; i < k; i++) {
            p_last = p_last->next;
        }
        while (p_last->next != nullptr) {
            pre = pre->next;
            p_last = p_last->next;
        }
        ListNode *tmp = head;
        head = pre->next;
        pre->next = nullptr;
        p_last->next = tmp;
        return head;
    }
};

int main() {
    vector<int> vec = { 1, 2, 3, 4, 5, 6 };
    ListNode *head = construct_list(vec);
    Solution obj;
    head = obj.rotateRight(head, 3);
    print_list(head);

    return 0;
}
