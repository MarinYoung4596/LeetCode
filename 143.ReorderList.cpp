/*
143. Reorder List.
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/


#include "ListNode.h"
// Ordinary List: 1->2->3->4->5->6->7
// Reordered List:1->(7)->2->(6)->3->(5)->4


// First Solution: Time Complexity: O(N), Space Complexity: O(N)
class Solution {
public:
    void reorderList(ListNode* head) {
        std::vector<int> vec;
        for (auto node = head; node != nullptr; node = node->next) {
            vec.push_back(node->val);
        }
        auto idx = 0;
        for (auto node = head; node != nullptr node = node->next) {
            if (idx % 2 == 1) {
                node->val = vec[vec.size() - 1 - idx / 2];
            } else {
                node->val = vec[idx / 2];
            }
            ++idx;
        }
        return head;
    }
};


// Second Solution: Time complexity: O(N), space complexity O(1)
class Solution2 {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        ListNode* start = head;
        while (start->next != nullptr && start->next->next != nullptr) {
            ListNode* last = start;
            // loop to traverse to last node
            while (last->next != nullptr && last->next->next != nullptr) {
                last = last->next;
            }
            last->next->next = start->next;
            start->next = last->next;
            last->next = nullptr;
            start = start->next->next;
        }
    }
};