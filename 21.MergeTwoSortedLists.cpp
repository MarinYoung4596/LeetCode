/*
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.
*/
#include "ListNode.h"


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }

        ListNode head(0);
        ListNode *p_curr = &head;
        for (; l1 != nullptr && l2 != nullptr; p_curr = p_curr->next) {
            if (l1->val < l2->val) {
                p_curr->next = l1;
                l1 = l1->next;
            } else if (l1->val > l2->val) {
                p_curr->next = l2;
                l2 = l2->next;
            } else {
                p_curr->next = l1;
                l1 = l1->next;

                p_curr = p_curr->next;

                p_curr->next = l2;
                l2 = l2->next;
            }
        }
        if (l1 != nullptr) {
            p_curr->next = l1;
        } else {
            p_curr->next = l2;
        }
        return head.next;
    }
};