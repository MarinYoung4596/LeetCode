/*
Given a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.

For example,
    Given 1->2->3->3->4->4->5, return 1->2->5.
    Given 1->1->1->2->3, return 2->3.
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode saved_head(-1);
        saved_head.next = head;

        ListNode *pre = &saved_head, *curr = &saved_head;
        ListNode *to_be_deleted = nullptr;

        curr = curr->next;
        for (; curr != nullptr; ) {
            if (curr->next != nullptr && curr->val == curr->next->val) {
                to_be_deleted = curr;
            }
            if (to_be_deleted != nullptr && curr->val == to_be_deleted->val) {
                pre->next = curr->next;
                curr = curr->next;
                continue;
            }
            pre = pre->next;
            curr = curr->next;
        }
        return saved_head.next;
    }
};
