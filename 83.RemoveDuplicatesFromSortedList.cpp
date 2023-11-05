/*
Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
    Given 1->1->2, return 1->2.
    Given 1->1->2->3->3, return 1->2->3.
*/

#include <vector>
#include "ListNode.h"

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // 非最优写法，题目给定的是有序链表
        vector<int> valueList;
        ListNode *pCurr, *pre;
        pCurr = pre = head;
        for (; pCurr != NULL; pCurr = pCurr->next) {
            // if found, delete the current node
            if (findVal(valueList, pCurr->val)) {
                pre->next = pCurr->next;
                delete pCurr;
            } else {
                pre = pCurr;
            }
        }
        return head;
    }

private:
    bool findVal(vector<int> &valueList, int val) {
        vector<int>::iterator iter = valueList.begin();
        for (; iter != valueList.end(); iter++) {
            if (*iter == val) {
                return true;
            }
        }
        valueList.push_back(val);
        return false;
    }
};

// Second Solution
class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode saved_head(-1);
        saved_head.next = head;

        ListNode* pre = head;
        ListNode* cur = head->next;
        while (cur != nullptr) {
            if (pre->val == cur->val) {
                pre->next = cur->next;
                delete cur;
            } else {
                pre = cur;
            }
            cur = pre->next;
        }
        return saved_head.next;
    }
};
