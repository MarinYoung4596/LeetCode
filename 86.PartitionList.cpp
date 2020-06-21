/*
86. Partition List

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x. 

You should preserve the original relative order of the nodes in each of the two partitions. 

For example,
 Given 1->4->3->2->5->2 and x = 3,
 return 1->2->2->4->3->5. 

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode savedSmaller(-1), savedLarger(-1);
        
        ListNode *smaller = &savedSmaller; // use address 
        ListNode *larger = &savedLarger;
        
        for (ListNode *p = head; p != nullptr; p = p->next)
        {
            if (p->val < x)
            {
                smaller->next = p;
                smaller = smaller->next;
            }
            else
            {
                larger->next = p;
                larger = larger->next;
            }
        }
        smaller->next = savedLarger.next;
        larger->next = nullptr; // prevent circuler
        
        return savedSmaller.next;
    }
};