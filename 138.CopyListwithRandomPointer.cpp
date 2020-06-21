/*
138. Copy List with Random Pointer

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null. 

Return a deep copy of the list.

*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (nullptr == head) return head;

        RandomListNode savedHead(-1);
        // copy value and insert
        for (RandomListNode *p = head; p != nullptr;) {
            // copy
            RandomListNode *pCopy = new RandomListNode(p->label);
            // insert
            pCopy->next = p->next;
            p->next = pCopy;
            
            // save head
            if (p == head) {
                savedHead.next = pCopy;
            }
            // scan
            p = p->next->next;
        }
         // copy random pointer
        for (RandomListNode *p = head, *q = head->next; q != nullptr && p != nullptr; ) {
            // assert that q->random isn't nullptr
            q->random = (p->random == nullptr ? nullptr : p->random->next);
           
            // scan
            p = p->next->next;
            if (p != nullptr) {
                q = q->next->next;
            }
        }
        // split from original list
        for (RandomListNode *p = head, *q = head->next; q != nullptr && p != nullptr; ) {
            p->next = q->next;
            p = p->next;
            if (p != nullptr) {
                q->next = p->next;
                q = q->next;
            }
        }
        
        return savedHead.next;
    }
};
