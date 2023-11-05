/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
    What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:
    Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 8 -> 0 -> 7

*/


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> s1;
        get_value(l1, s1);
        std::stack<int> s2;
        get_value(l2, s2);

        std::vector<int> vec;
        int carry = 0;
        while (!s1.empty() || !s2.empty()) {
            int v1 = s1.empty() ? 0 : s1.top();
            int v2 = s2.empty() ? 0 : s2.top();
            int v = (v1 + v2 + carry) % 10;
            carry = (v1 + v2 + carry) / 10;
            vec.push_back(v);
            if (!s1.empty()) {
                s1.pop();
            }
            if (!s2.empty()) {
                s2.pop();
            }
        }
        if (carry != 0) {
            vec.push_back(carry);
        }
        std::reverse(vec.begin(), vec.end());
        ListNode dummy(-1);
        auto p = &dummy;
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            p->next = new ListNode(*it, nullptr);
            p = p->next;
        }
        return dummy.next;
    }

private:
    void get_value(ListNode* head, std::stack<int> &s) {
        while (head != nullptr) {
            s.push(head->val);
            head = head->next;
        }
    }
};