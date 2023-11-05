/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    508.MostFrequentSubtreeSum.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/23 13:32:50
*   @brief:

Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.
The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).


Example 1:
    (pic)
    Input: root = [5,2,-3]
    Output: [2,-3,4]

Example 2:
    (pic)
    Input: root = [5,2,-5]
    Output: [2]


Constraints:
    The number of nodes in the tree is in the range [1, 10^4].
    -10^5 <= Node.val <= 10^5

*****************************************************************/

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        std::unordered_map<int, int> node_freq_map;
        int max_freq = 0;
        dfs(root, node_freq_map, max_freq);

        vector<int> result;
        for (const auto &[node_sum, freq] : node_freq_map) {
            if (freq == max_freq) {
                result.push_back(node_sum);
            }
        }
        return result;
    }

private:
    int dfs(TreeNode* root,
            std::unordered_map<int, int> &node_freq_map,
            int &max_freq) {
        if (nullptr == root) {
            return 0;
        }
        auto left_sum = dfs(root->left, node_freq_map, max_freq);
        auto right_sum = dfs(root->right, node_freq_map, max_freq);
        auto cur_sum = left_sum + right_sum + root->val;
        if (node_freq_map.find(cur_sum) != node_freq_map.end()) {
            node_freq_map[cur_sum] += 1;
        } else {
            node_freq_map[cur_sum] = 1;
        }
        if (max_freq < node_freq_map[cur_sum]) {
            max_freq = node_freq_map[cur_sum];
        }
        return cur_sum;
    }
};