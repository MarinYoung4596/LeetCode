/*
You are given the head of a singly linked-list. The list can be represented as:
    L_0 → L_1 → … → L_(n - 1) → L_n

Reorder the list to be on the following form:
    L_0 → L_n → L1 → L_(n - 1) → L_2 → L_(n - 2) → …

You may not modify the values in the list's nodes. Only nodes themselves may be changed.


Example 1:
    (pic)
    Input: head = [1,2,3,4]
    Output: [1,4,2,3]

Example 2:
    (pic)
    Input: head = [1,2,3,4,5]
    Output: [1,5,2,4,3]


Constraints:
    The number of nodes in the list is in the range [1, 5 * 10^4].
    1 <= Node.val <= 1000
*/


#include "ListNode.h"
// Ordinary List: 1->2->3->4->5->6->7
// Reordered List:1->(7)->2->(6)->3->(5)->4


/**
 * @brief First Solution: 借用空间临时存储，val copy
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
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


/**
 * @brief Second Solution:
 * Time complexity: O(N^2),
 * space complexity O(1)
 */
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

/**
 * @brief Third Solution: 1）分为左右两部分；2）反转右半部分；3）交替拼接左右两部分
 */
class Solution3 {
public:
    void reorderList(ListNode* head) {
        // step1: 找到链表后半部分
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre_slow = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            pre_slow = slow;
            slow = slow->next;
        }

        // step2：断开左右链表连接
        if (pre_slow != nullptr) {
            pre_slow->next = nullptr;
        }

        // step3: 反转后半部分
        ListNode* pre = nullptr;
        ListNode* cur = slow;
        while (cur != nullptr) {
            auto next = cur->next;

            cur->next = pre;
            pre = cur;
            cur = next;
        }

        // step4: 交替 merge 两个链表
        auto p_left = head; // 左侧链表
        auto p_right = pre;  // 右侧链表
        auto dummy_head = new ListNode(-1);
        auto p = dummy_head;
        while (p_left != nullptr && p_right != nullptr) {
            auto tmp_left = p_left->next;
            p_left->next = nullptr;
            p->next = p_left;
            p_left = tmp_left;

            p = p->next;

            auto tmp_right = p_right->next;
            p_right->next = nullptr;
            p->next = p_right;
            p_right = tmp_right;

            p = p->next;
        }
        if (p_right != nullptr) {
            p->next = p_right;
        } else {
            p->next = p_left;
        }
        head = dummy_head->next;
    }
};