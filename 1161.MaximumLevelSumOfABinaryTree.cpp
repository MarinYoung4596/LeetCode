/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1161.MaximumLevelSumOfABinaryTree.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/10 00:17:10
*   @brief:

Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.


Example 1:
    (pic)
    Input: root = [1,7,0,7,-8,null,null]
    Output: 2
    Explanation:
        Level 1 sum = 1.
        Level 2 sum = 7 + 0 = 7.
        Level 3 sum = 7 + -8 = -1.
    So we return the level with the maximum sum which is level 2.

Example 2:
    Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
    Output: 2


Constraints:
    The number of nodes in the tree is in the range [1, 10^4].
    -10^5 <= Node.val <= 10^5

*****************************************************************/


class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);

        auto cur_level = 1;
        auto max_sum = INT_MIN;
        auto max_level = -1;
        while (!q.empty()) {
            auto queue_len = q.size();
            auto cur_sum = 0;
            for (auto i = 0; i < queue_len; ++i) {
                auto node = q.front();
                q.pop();
                cur_sum += node->val;

                if (nullptr != node->left) {
                    q.push(node->left);
                }
                if (nullptr != node->right) {
                    q.push(node->right);
                }
            }
            if (cur_sum > max_sum) {
                max_sum = cur_sum;
                max_level = cur_level;
            }
            ++cur_level;
        }
        return max_level;
    }
};