/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    971.FlipBinaryTreeToMatchPreorderTraversal.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/05 17:14:35
*   @brief:

You are given the root of a binary tree with n nodes, where each node is uniquely assigned a value from 1 to n. You are also given a sequence of n values voyage, which is the desired pre-order traversal of the binary tree.

Any node in the binary tree can be flipped by swapping its left and right subtrees. For example, flipping node 1 will have the following effect:
(pic)
Flip the smallest number of nodes so that the pre-order traversal of the tree matches voyage.

Return a list of the values of all flipped nodes. You may return the answer in any order. If it is impossible to flip the nodes in the tree to make the pre-order traversal match voyage, return the list [-1].


Example 1:
    (pic)
    Input: root = [1,2], voyage = [2,1]
    Output: [-1]
    Explanation: It is impossible to flip the nodes such that the pre-order traversal matches voyage.


Example 2:
    (pic)
    Input: root = [1,2,3], voyage = [1,3,2]
    Output: [1]
    Explanation: Flipping node 1 swaps nodes 2 and 3, so the pre-order traversal matches voyage.


Example 3:
    (pic)
    Input: root = [1,2,3], voyage = [1,2,3]
    Output: []
    Explanation: The tree's pre-order traversal already matches voyage, so no nodes need to be flipped.


Constraints:
    The number of nodes in the tree is n.
    n == voyage.length
    1 <= n <= 100
    1 <= Node.val, voyage[i] <= n
    All the values in the tree are unique.
    All the values in voyage are unique.

*****************************************************************/


class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> result;
        auto index = 0;
        auto ret = dfs(root, voyage, index, result);
        return ret ? result : vector<int>({-1});
    }

private:
    bool dfs(TreeNode* root, vector<int> &voyage, int &index, vector<int> &flips) {
        if (nullptr == root) {
            return true;
        }
        if (root->val != voyage[index++]) { // TODO：这里没有判断 index 是否合法
            return false;
        }
        if (root->left != nullptr && root->left->val != voyage[index]) { // 此时，需要翻转
            flips.push_back(root->val);
            return dfs(root->right, voyage, index, flips) &&
                   dfs(root->left, voyage, index, flips);
        } else { // 无需翻转
            return dfs(root->left, voyage, index, flips) &&
                   dfs(root->right, voyage, index, flips);
        }
    }
};