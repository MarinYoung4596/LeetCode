/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    513.FindBottomLeftTreeValue.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/23 15:14:48
*   @brief:

Given the root of a binary tree, return the leftmost value in the last row of the tree.


Example 1:
    (pic)
    Input: root = [2,1,3]
    Output: 1

Example 2:
    (pic)
    Input: root = [1,2,3,4,null,5,6,null,null,7]
    Output: 7


Constraints:
    The number of nodes in the tree is in the range [1, 10^4].
    -2^31 <= Node.val <= 2^31 - 1

*****************************************************************/


class Solution {
public:
    // 先序遍历（同时记录深度），1）如果左叶子 深度一致，丢弃；2）否则，存储并记录深度
    int findBottomLeftValue(TreeNode* root) {
        int target_value;
        int target_depth = INT_MIN;
        unordered_map<int, int> depth_value_map;  // depth : value
        dfs(root, depth_value_map, target_value, target_depth, 0);
        return target_value;
    }

private:
    void dfs(TreeNode* root,
            unordered_map<int, int> &depth_value_map,
            int &target_value,
            int &target_depth,
            int depth) {
        //
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            if (depth_value_map.count(depth) < 1) {
                depth_value_map[depth] = root->val;
                if (target_depth < depth) {
                    target_depth = depth;
                    target_value = root->val;
                }
            }
            return;
        }
        dfs(root->left, depth_value_map, target_value, target_depth, depth + 1);
        dfs(root->right, depth_value_map, target_value, target_depth, depth + 1);
    }
};