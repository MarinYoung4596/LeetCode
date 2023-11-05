/*
You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes contain
a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include <iostream>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode *head = NULL, *rear = NULL, *new_node = NULL;
        int carry = 0, val = 0;
        while (l1 || l2 ) {
            if (!l1) {
                val = add(0, l2->val, carry);
                l2 = l2->next;
            } else if (!l2) {
                val = add(l1->val, 0, carry);
                l1 = l1->next;
            } else {
                val = add(l1->val, l2->val, carry);
                l1 = l1->next;
                l2 = l2->next;
            }
            new_node = new ListNode(val);
            if (!head) {
                head = new_node;
            }
            if (!rear) {
                rear = new_node;
            } else {
                rear->next = new_node;
                rear = rear->next;
            }
        }
        if (carry != 0 && rear != NULL) {
            rear->next = new ListNode(carry);
        }
        return head;
    }

private:
    int add(int a, int b, int &carry) {
        int c = a + b + carry;
        carry = c / 10;
        return c % 10;
    }
};