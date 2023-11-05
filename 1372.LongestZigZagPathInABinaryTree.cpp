/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1372.LongestZigZagPathInABinaryTree.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/06 23:21:31
*   @brief:

You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:
    Choose any node in the binary tree and a direction (right or left).
    If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
    Change the direction from right to left or from left to right.
    Repeat the second and third steps until you can't move in the tree.
    Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.



Example 1:
    (pic)
    Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
    Output: 3
    Explanation: Longest ZigZag path in blue nodes (right -> left -> right).

Example 2:
    (pic)
    Input: root = [1,1,1,null,1,null,null,1,1,null,1]
    Output: 4
    Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).

Example 3:
    Input: root = [1]
    Output: 0


Constraints:
    The number of nodes in the tree is in the range [1, 5 * 10^4].
    1 <= Node.val <= 100

*****************************************************************/

class Solution {
public:
    int longestZigZag(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        auto left = dfs(root->left, 0, true);
        auto right = dfs(root->right, 0, false);
        return std::max(left, right);
    }

private:
    int dfs(TreeNode* root, int path_len, bool is_left) {
        if (nullptr == root) {
            return path_len;
        }

        auto left = is_left ? \
                dfs(root->left, 0, true) : \
                dfs(root->left, path_len + 1, true);
        auto right = is_left ? \
                dfs(root->right, path_len + 1, false) : \
                dfs(root->right, 0, false);

        return std::max(left, right);
    }
};