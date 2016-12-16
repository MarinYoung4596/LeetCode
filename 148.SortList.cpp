/*
148. Sort List

Sort a linked list in O(n log n) time using constant space complexity.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// first Solution ： merge sort
class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr) return head;
        
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr; // IMPORTANT to avoid endless
        
        return merge(sortList(head), sortList(fast));
    }
    
private:
    ListNode* merge(ListNode *left, ListNode *right)
    {
        ListNode tmp(-1);
        ListNode* curr = &tmp;
        
        while (left != nullptr && right != nullptr)
        {
            if (left->val < right->val)
            {
                curr->next = left;
                left = left->next;
            }
            else
            {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        if (left != nullptr) curr->next = left;
        if (right != nullptr) curr->next = right;
        return tmp.next;
    }
};

// second solution: Quick Sort
// simple swap operation, TLE in big data
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
    ListNode* sortList(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr) return head;
        
        QuickSort(head, nullptr);
        return head;
    }
    
private:
    void QuickSort(ListNode* head, ListNode* end)
    {
        if (head != end)
        {
            ListNode* pivot = getPartition(head, end);
            QuickSort(head, pivot);
            QuickSort(pivot->next, end);
        }
    }
    
    ListNode* getPartition(ListNode* head, ListNode* end)
    {
        auto pivot = head->val;
        ListNode* p = head;
        ListNode* q = head->next;
        
        for (; q != end; q = q->next)
        {
            if (q->val < pivot)
            {
                p = p->next;
                swap(p->val, q->val);
            }
        }
        swap(p->val, head->val); // put pivot at the middle position
        return p;
    }
};


// three-ways QuickSort
// see: https://discuss.leetcode.com/topic/9149/3-ways-quicksort-o-1-sapce-cpp-solution
// and: http://www.2cto.com/kf/201401/273363.html
