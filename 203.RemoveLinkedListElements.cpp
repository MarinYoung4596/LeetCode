/*
Remove all elements from a linked list of integers that have value val.

Example
    Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
    Return: 1 --> 2 --> 3 --> 4 --> 5
*/

#include "ListNode.h"
#include <iostream>


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *pre = head;
        ListNode *p = head;
        for (; p != nullptr; ) {
            if (val != p->val) {
                pre = p;
                p = p->next;
                continue;
            }
            if (p == head) {        // Head
                ListNode *tmp = head;
                head = head->next;
                p = pre = head;
                delete tmp;
                continue;
            }
            if (p->next == nullptr) {    // Tail
                pre->next = nullptr;
                delete p;
                break;
            }
            // Middle
            ListNode *tmp = p;
            pre->next = p->next;
            p = p->next;
            delete tmp;
        }
        return head;
    }
};

int main(int argc, char **argv) {
    vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    ListNode* head = construct_list(vec);
    print_list(head);

    Solution obj;
    p = obj.removeElements(head, 5);    // Middle
    print_list(p);

    p = obj.removeElements(p, 1);        // Head
    print_list(p);

    p = obj.removeElements(p, 0);        // Tail
    print_list(p);

    ListNode *singleNode = new ListNode(100);
    p = obj.removeElements(singleNode, 100);    // SingleNode
    print_list(p);

    return 0;
}
