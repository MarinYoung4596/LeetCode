/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    958.CheckCompletenessOfABinaryTree.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/12/03 17:39:30
*   @brief:

Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last,
is completely filled, and all nodes in the last level are as far left as possible.
It can have between 1 and 2h nodes inclusive at the last level h.


Example 1:
    (pic)
    Input: root = [1,2,3,4,5,6]
    Output: true
    Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}),
        and all nodes in the last level ({4, 5, 6}) are as far left as possible.

Example 2:
    (pic)
    Input: root = [1,2,3,4,5,null,7]
    Output: false
    Explanation: The node with value 7 isn't as far left as possible.


Constraints:
    The number of nodes in the tree is in the range [1, 100].
    1 <= Node.val <= 1000

*****************************************************************/


class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        auto reach_at_end = false;
        while (!q.empty()) {
            const auto queue_len = q.size();
            for (auto i = 0; i < queue_len; ++i) {
                auto node = q.front();
                q.pop();
                if (node == nullptr) {
                    reach_at_end = true;
                    continue;
                }
                if (reach_at_end) {
                    return false;
                }
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};