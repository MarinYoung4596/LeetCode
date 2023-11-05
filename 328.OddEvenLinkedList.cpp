/*
328. Odd Even Linked List

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.


Example:
    Given 1->2->3->4->5->NULL,
    return 1->3->5->2->4->NULL.

Note:
    The relative order inside both the even and odd groups should remain as it was in the input.
    The first node is considered odd, the second node even and so on ...

*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode SavedOdd(-1), SavedEven(-1);
        ListNode *odd = &SavedOdd, *even = &SavedEven;

        int count = 1;
        for (ListNode *p = head; p != nullptr; p = p->next, ++count)
        {
            // Please note here we are talking about the node number and not the value in the nodes.
            if (0x01 & count)
            {
                odd->next = p;
                odd = odd->next;
            }
            else
            {
                even->next = p;
                even = even->next;
            }
        }
        odd->next = SavedEven.next;
        even->next = nullptr;
        return SavedOdd.next;
    }
};