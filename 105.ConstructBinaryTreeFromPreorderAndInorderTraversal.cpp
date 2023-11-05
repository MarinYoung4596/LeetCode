/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note: You may assume that duplicates do not exist in the tree.
*/

#include "TreeNode.h"

class Solution {
private:
    TreeNode* preInBulid(
            vector<int> &pre_order, int pre_first, int pre_last,
            vector<int> &in_order, int in_first, int in_last) {
        TreeNode *root = new TreeNode(pre_order[pre_first]);

        int i = in_first;
        for (; in_order[i] != root->val; i++);
        int left_len = i - in_first;
        int right_len = in_last - i;

        if (left_len) {
            root->left = preInBulid(
                pre_order, pre_first + 1, pre_first + left_len,
                in_order, in_first, in_first + left_len - 1);
        } else {
            root->left = nullptr;
        }

        if (right_len) {
            root->right = preInBulid(
                pre_order, pre_last - right_len + 1, pre_last,
                in_order, in_last - right_len + 1, in_last);
        } else {
            root->right = nullptr;
        }

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }
        return preInBulid(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
