/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    662.MaximumWidthOfBinaryTree.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/03/07 10:30:44
*   @brief:

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.


Example 1:
    Input: root = [1,3,2,5,3,null,9]
    Output: 4
    Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Example 2:
    Input: root = [1,3,2,5,null,null,9,6,null,7]
    Output: 7
    Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Example 3:
    Input: root = [1,3,2,5]
    Output: 2
    Explanation: The maximum width exists in the second level with length 2 (3,2).


Constraints:
    The number of nodes in the tree is in the range [1, 3000].
    -100 <= Node.val <= 100

*****************************************************************/


// First Solution: bfs

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int result = INT_MIN;
        queue<pair<TreeNode*, uint64_t>> q;
        q.push(make_pair(root, 1));
        while (!q.empty()) {
            uint64_t queue_len = q.size();
            uint64_t begin_index = 0;
            uint64_t end_index = 0;
            for (uint64_t i = 0; i < queue_len; ++i) {
                auto pair = q.front();
                q.pop();

                auto node = pair.first;
                auto index = pair.second;

                if (i == 0) {
                    begin_index = index;
                }
                if (i == queue_len - 1) {
                    end_index = index;
                }

                if (nullptr != node->left) {
                    q.push(make_pair(node->left, index * 2));
                }
                if (nullptr != node->right) {
                    q.push(make_pair(node->right, index * 2 + 1));
                }
            }
            int cur_width = end_index - begin_index + 1;
            result = max(result, cur_width);
        }
        return result;
    }
};