/*
83. Remove Duplicates from Sorted List
Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

#include <vector>
#include "ListNode.h"

bool findVal(vector<int> &valueList, int val)
{
    vector<int>::iterator iter = valueList.begin();
    for (; iter != valueList.end(); iter++)
    {
        if (*iter == val)
            return true;
    }
    // if not found
    valueList.push_back(val);
    return false;
}

ListNode *deleteDuplicates(ListNode *head)
{
    vector<int> valueList;
    ListNode *pCurr, *pre;
    pCurr = pre = head;
    for (; pCurr != NULL; pCurr = pCurr->next)
    {
        // if found, delete the current node
        if (findVal(valueList, pCurr->val))
        {
            pre->next = pCurr->next;
            delete pCurr;
        }
        else
            pre = pCurr;
    }
    return head;
}
