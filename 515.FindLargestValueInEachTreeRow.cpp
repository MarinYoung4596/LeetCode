/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    515.FindLargestValueInEachRow.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/23 20:09:16
*   @brief:

Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).


Example 1:
    Input: root = [1,3,2,5,3,null,9]
    Output: [1,3,9]

Example 2:
    Input: root = [1,2,3]
    Output: [1,3]


Constraints:
    The number of nodes in the tree will be in the range [0, 10^4].
    -2^31 <= Node.val <= 2^31 - 1

*****************************************************************/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }

private:
    void dfs(TreeNode* root, int depth, vector<int> &max_nodes) {
        if (nullptr == root) {
            return;
        }
        if (depth >= max_nodes.size()) {
            max_nodes.push_back(root->val);
        } else {
            if (max_nodes[depth] < root->val) {
                max_nodes[depth] = root->val;
            }
        }
        dfs(root->left, depth + 1, max_nodes);
        dfs(root->right, depth + 1, max_nodes);
    }
};