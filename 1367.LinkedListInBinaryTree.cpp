/*
Given a binary tree root and a linked list with head as the first node.
Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.
In this context downward path means a path that starts at some node and goes downwards.

Example 1:
    (pic)
    Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
    Output: true
    Explanation: Nodes in blue form a subpath in the binary Tree.

Example 2:
    (pic)
    Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
    Output: true

Example 3:
    Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
    Output: false
    Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.


Constraints:
    1 <= node.val <= 100 for each node in the linked list and binary tree.
    The given linked list will contain between 1 and 100 nodes.
    The given binary tree will contain between 1 and 2500 nodes.
*/


class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == nullptr) {
            return true;
        } else if (root == nullptr) {
            return false;
        }
        auto left_search = isSubPath(head, root->left);
        auto right_search = isSubPath(head, root->right);
        auto curr_search = dfs(head, root);
        return left_search || right_search || curr_search;
    }

private:
    bool dfs(ListNode* head, TreeNode* root) {
        if (head == nullptr) {
            return true;
        } else if (root == nullptr) {
            return false;
        }
        if (head->val == root->val) {
            return dfs(head->next, root->left) || dfs(head->next, root->right);
        } else {
            return false;
        }
    }
};