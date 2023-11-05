/**
Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :
    Input: root = [4,2,6,1,3,null,null]
    Output: 1
    Explanation:
        Note that root is a TreeNode object, not an array.
        The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
         / \
        2   6
       / \
      1   3

    while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.


Note:
    The size of the BST will be between 2 and 100.
    The BST is always valid, each node's value is an integer, and each node's value is different.
    This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
*/


class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        return find_min_diff(root, nullptr, nullptr, INT_MAX);
    }

private:
    int find_min_diff(TreeNode* root, TreeNode* min_node, TreeNode* max_node, int result) {
        if (nullptr == root) {
            return result;
        }
        auto curr_min_diff = std::min(
            nullptr != min_node ? std::abs(root->val - min_node->val) : result,
            nullptr != max_node ? std::abs(root->val - max_node->val) : result
        );
        if (curr_min_diff < result) {
            result = curr_min_diff;
        }
        auto left_min_diff = find_min_diff(root->left, min_node, root, result); // left child, root is max_node
        auto right_min_diff = find_min_diff(root->right, root, max_node, result); // right child, root is min_node
        if (left_min_diff < result) {
            result = left_min_diff;
        }
        if (right_min_diff < result) {
            result = right_min_diff;
        }
        return result;
    }
};
