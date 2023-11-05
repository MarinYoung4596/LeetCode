/**
Given a singly linked list, determine if it is a palindrome.

Follow up:
    Could you do it in O(n) time and O(1) space?
*/

#include <iostream>
#include <stack>
#include <vector>

#include "ListNode.h"

using namespace std;

// second solution: reverse list partly
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        if (head->next->next == nullptr) {
            return head->val == head->next->val;
        }
        // 快慢指针, 找到链表中间节点
        ListNode *mid = head;
        for (ListNode *p = head;
                p != nullptr && p->next != nullptr;
                p = p->next->next, mid = mid->next);


        // 然后将后半部分逆序反转
        ListNode *p = mid;
        ListNode *pre = nullptr;
        ListNode *next = p->next;

        p->next = nullptr;
        for (; next != nullptr;) {
            pre = p;
            p = next;
            next = next->next;

            p->next = pre; // reverse
        }

        // 最后同时走，判断是否相等
        for (ListNode *pFirst = head, *pLast = p;
                pLast != nullptr;
                pFirst = pFirst->next, pLast = pLast->next) {
            if (pFirst->val != pLast->val) {
                return false;
            }
        }
        return true;
    }
};

// first solution: stack
class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        int len = 0;
        for (ListNode *p = head; p != nullptr; ++len, p = p->next) {
            s.push(p->val);
        }

        ListNode *p = head;
        for(auto i = 0; i * 2 < len; ++i, p = p->next) {
            auto value = s.top();
            if(value != p->val) {
                return false;
            }
            s.pop();
            p = p->next;
        }
        return true;
    }
};

int main(int argc, char **argv) {
    vector<int> nums = { 2, 3, 5, 2};
    ListNode *head = construct_list(nums);
    print_list(head);

    Solution obj;
    std::cout << (obj.isPalindrome(head) ? "TRUE": "FALSE") << std::endl;

    return 0;
}
