/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    95.UniqueBinarySearchTreesII.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/02/12 19:09:51
*   @brief:

Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

Example 1:
    Input: n = 3
    Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

Example 2:
    Input: n = 1
    Output: [[1]]


Constraints:
    1 <= n <= 8

*****************************************************************/

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return build_tree(1, n);
    }

private:
    vector<TreeNode*> build_tree(int low, int high) {
        vector<TreeNode*> result;
        if (low > high) {
            result.push_back(nullptr);
            return result;
        }
        for (auto i = low; i <= high; ++i) { // root 节点
            auto left_trees = build_tree(low, i - 1);  // 左子树 所有可能子树
            auto right_trees = build_tree(i + 1, high); // 右子树 所有可能子树
            for (auto left: left_trees) {
                for (auto right : right_trees) {
                    auto root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};
