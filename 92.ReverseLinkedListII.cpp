/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
    Given 1->2->3->4->5->NULL, m = 2 and n = 4,
    return 1->4->3->2->5->NULL.

Note: Given m, n satisfy the following condition:
    1 ≤ m ≤ n ≤ length of list.
*/

#include "ListNode"


class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == nullptr) {
            return nullptr;
        }
        if (m == n) {
            return head;
        }
        ListNode dummy_head(0);
        dummy_head.next = head;
        /*
        Index    1    ->   m          n        ->Len
        List    Head->...->x->y->...->z->......->Tail

        *PROCESS:
        List:   head->...->1->2->3->4->5->......->Tail
        1                  p     r
        2                 pre <- p  r
        3                        pre <- p r
        4                           pre <- p r
        *CODE:
        SCAN:        pre = p;    p = r;    r = r->next;
        REVERSE:    p->next = pre;
        */
        ListNode *p = &dummy_head;
        for (int i = 0; i < m - 1; ++i) {
            p = p->next;
        }

        ListNode *pre_m_node = p;    // pre_m_node    ->    NODE(m_node-1)
        p = pre_m_node->next;        // p             ->    NODE(m_node)
        ListNode *m_node = p;        // m_node        ->    NODE(m_node) save the position of m_node
        ListNode *r = p->next;       // r             ->    NODE(m_node+1)
        for (int i = m; i < n && r != NULL; ++i) {
            ListNode *pre = p;
            p = r;
            r = r->next;    // SCAN

            p->next = pre;    // REVERSE
        }
        pre_m_node->next = p;        // NODE(m_node - 1)    ->    NODE(N)
        m_node->next = r;            // NODE(m_node)        ->    NODE(N+1)

        return dummy_head.next;
    }
};


int main(int argv, char **argc) {
    vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    ListNode *head = construct_list(vec);
    print_list(head);
    Solution obj;
    p = obj.reverseBetween(head, 4, 8);
    print_list(p);

    return 0;
}
