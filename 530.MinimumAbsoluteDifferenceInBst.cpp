/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:
    Input:
       1
        \
         3
        /
       2
    Output: 1
    Explanation: The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).


Note:
    There are at least two nodes in this BST.
    This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

*/

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        return find_min_diff(root, nullptr, nullptr, INT_MAX);
    }

private:
    int find_min_diff(TreeNode* root, TreeNode* min_node, TreeNode* max_node, int result) {
        if (nullptr == root) {
            return result;
        }
        auto curr_min_diff = std::min(
            nullptr != min_node ? std::abs(root->val - min_node->val) : result,
            nullptr != max_node ? std::abs(root->val - max_node->val) : result);
        auto left_min_diff = find_min_diff(root->left, min_node, root, result);
        auto right_min_diff = find_min_diff(root->right, root, max_node, result);
        return std::min({result, left_min_diff, right_min_diff, curr_min_diff});
    }
};