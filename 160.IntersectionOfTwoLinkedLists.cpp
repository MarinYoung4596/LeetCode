/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists :
A :      a1 → a2
                ↘
                 c1 → c2 → c3
                ↗
B : b1 → b2 → b3
    begin to intersect at node c1.

Notes :
    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.
Solutions:
    If they are intersect at node cx; then their tail will be the same;

*/
#include "ListNode.h"

class Solution {
public:
ListNode* getIntersectionNode(ListNode* head_a, ListNode* head_b) {
    if (head_a == nullptr || head_b == nullptr) {
        return nullptr;
    }

    ListNode *p_curr_a = head_a;
    int len_a = 1;
    while (p_curr_a->next != nullptr) {
        p_curr_a = p_curr_a->next;
        len_a++;
    }

    ListNode *p_curr_b = head_b;
    int len_b = 1;
    while (p_curr_b->next != nullptr) {
        p_curr_b = p_curr_b->next;
        len_b++;
    }
    if (p_curr_a != p_curr_b) { // if pTailA != pTailB
        return nullptr;
    }

    // 1) 长的链表从头开始 走 sub 步, 打平长度差距
    int sub = len_a - len_b;
    if (sub > 0) {            // len_a > len_b
        for (; sub; --sub) {
            head_a = head_a->next;
        }
    } else if (sub < 0)    {    // len_a < len_b
        for (; sub < 0; ++sub) {  // attention: sub<0; in case that sub = -1, so that !sub is wrong
            head_b = head_b->next;
        }
    }
    // 2) 然后同时往后走,直至相等
    for (; head_a != head_b; head_a = head_a->next, head_b = head_b->next);
    return head_a;
}
};