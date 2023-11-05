/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up: Can you solve it without using extra space?
*/
#include "ListNode.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *meeting_node = meetingNode(head);
        if (meeting_node == nullptr) {
            return nullptr;
        }

        // get the number of nodes in loop
        int nodes_in_loop = 1;
        for (ListNode *p_cur = meeting_node; p_cur->next != meeting_node; p_cur = p_cur->next) {
            ++nodes_in_loop;
        }

        ListNode *p_node_1 = head;
        for (int i = 0; i < nodes_in_loop; ++i) {
            p_node_1 = p_node_1->next;
        }

        ListNode *p_node_2 = head;
        for (; p_node_1 != p_node_2; p_node_1 = p_node_1->next, p_node_2 = p_node_2->next);
        return p_node_1;
    }

private:
    // Given a linked list, determine if it has a cycle in it.
    // if yes, return the meeting node, else return nullptr.
    // Same as 141. Linked list cycle
    ListNode *meetingNode(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                return fast;
            }
        }
        return nullptr;
    }
};