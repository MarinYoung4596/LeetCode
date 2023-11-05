/*
Given a linked list, remove the nth node from the end of list and return its head.


For example,
    Given linked list : 1->2->3->4->5, and n = 2.
    After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
    Given n will always be valid.
    Try to do this in one pass.
*/
#include "ListNode.h"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr || n <= 0) {
            return nullptr;
        }

        // for the case that there are only one element in *head
        // and when we delete *head, then no node to return.
        // e.g. ({1}, 1) --> {}
        ListNode dummy_head(0);
        dummy_head.next = head;

        // point to the address of dummy_head
        ListNode *pre = &dummy_head, *p_curr = &dummy_head;

        // make n-1 nodes included between *pre and *p_curr
        // named, pre->1->2->3->...->n-1->p_curr
        //               1  2  3       n-1   n
        // when p_curr == Tail, then pre->next (named, node 1) is the node to be deleted.
        for (int i = 0; i < n; i++) {
            // if p_curr == nullptr, means n is larger than the length of ListNode *head
            if (p_curr == nullptr) {
                return nullptr;
            }
            p_curr = p_curr->next;
        }
        // traversal until p_curr to the end of the list
        while (p_curr->next != nullptr) {
            pre = pre->next;
            p_curr = p_curr->next;
        }
        // delete the Nth node from the end
        ListNode *tmp = pre->next;
        pre->next = pre->next->next;
        delete tmp;

        return dummy_head.next;
    }
};
