/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1448.CountGoodNodesInBinaryTree.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/10 00:06:31
*   @brief:

Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.


Example 1:
    (pc)
    Input: root = [3,1,4,3,null,1,5]
    Output: 4
    Explanation: Nodes in blue are good.
        Root Node (3) is always a good node.
        Node 4 -> (3,4) is the maximum value in the path starting from the root.
        Node 5 -> (3,4,5) is the maximum value in the path
        Node 3 -> (3,1,3) is the maximum value in the path.


Example 2:
    (pic)
    Input: root = [3,3,null,4,2]
    Output: 3
    Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.

Example 3:
    Input: root = [1]
    Output: 1
    Explanation: Root is considered as good.


Constraints:
    The number of nodes in the binary tree is in the range [1, 10^5].
    Each node's value is between [-10^4, 10^4].
*****************************************************************/


class Solution {
public:
    int goodNodes(TreeNode* root) {
        auto max_value = root->val;
        return dfs(root, max_value);
    }

private:
    int dfs(TreeNode* root, int max_value) {
        if (nullptr == root) {
            return 0;
        }
        auto cur = 0;
        if (root->val >= max_value) {
            ++cur;
            max_value = root->val;
        }
        auto left = dfs(root->left, max_value);
        auto right = dfs(root->right, max_value);
        return cur + left + right;
    }
};