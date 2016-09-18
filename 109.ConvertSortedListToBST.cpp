/*
109. Convert Sorted List to Binary Search Tree
  
  Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (nullptr == head) return nullptr;
        
        return constructBST(head, nullptr);
    }
private:
    TreeNode* constructBST(ListNode *head, ListNode *end)
    {
        ListNode *mid = head;
        for (ListNode* q = head; 
            q != end && q->next != end; 
            mid = mid->next, q = q->next->next); // get mid pointer
        
        TreeNode *root = new TreeNode(mid->val); // mid
        if (head == mid) root->left = nullptr;
        else root->left = constructBST(head, mid);
        
        mid = mid->next; // next mid pointer
        if (mid == end) root->right = nullptr;
        else root->right = constructBST(mid, end);
        
        return root;
    }
};