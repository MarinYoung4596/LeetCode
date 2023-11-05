/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1382.BalanceABinarySearchTree.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/05 18:54:18
*   @brief:

Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.


Example 1:
    (pic)
    Input: root = [1,null,2,null,3,null,4,null,null]
    Output: [2,1,3,null,null,null,4]
    Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

Example 2:
    (pic)
    Input: root = [2,1,3]
    Output: [2,1,3]


Constraints:
    The number of nodes in the tree is in the range [1, 10^4].
    1 <= Node.val <= 10^5

*****************************************************************/

// 1）先中序遍历；2）再转换成 用有序数组构建 BST 的题目
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ordered_arr;
        inorder(root, ordered_arr);
        return construct(ordered_arr, 0, ordered_arr.size() - 1);
    }

private:
    void inorder(TreeNode *root, vector<int> &res) {
        if (nullptr == root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    TreeNode* construct(vector<int> &arr, int begin, int end) {
        if (end < begin) {
            return nullptr;
        }
        auto mid = (begin + end) >> 1;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = mid - begin > 0 ? construct(arr, begin, mid - 1) : nullptr;
        root->right = end - mid > 0 ? construct(arr, mid + 1, end) : nullptr;
        return root;
    }
};