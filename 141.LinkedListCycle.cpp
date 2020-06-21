/*
141. Linked List Cycle
Given a linked list, determine if it has a cycle in it.

Follow up :
Can you solve it without using extra space ?
*/
#include "ListNode.h"

/* Fist Solution: two pointers, one fast one slow
 * if they came cross, means that it has cycle
 * Time Complexity: O(N), Space Complexity: O(1)
*/
bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            return true;
        }
    }
    return false; 
}

/* Second Solution: 
 * use hash map, unordered_map<int, bool> visited
 * Time Complexity O(N), Space Complexity O(1)
*/
