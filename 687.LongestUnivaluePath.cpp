/*
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
The length of path between two nodes is represented by the number of edges between them.


Example 1:
Input:
              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2


Example 2:
Input:
              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2


Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
*/


// First Solution: 子空间重复遍历，时间复杂度较高
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        auto left = longestUnivaluePath(root->left);
        auto right = longestUnivaluePath(root->right);
        auto sum = dfs(root->left, root->val) + dfs(root->right, root->val);
        return std::max({left, right, sum});
    }

private:
    int dfs(TreeNode* root, int prev) {
        if (nullptr == root) {
            return 0;
        }
        if (root->val != prev) {
            return 0;
        }
        auto left = dfs(root->left, root->val) + 1;
        auto right = dfs(root->right, root->val) + 1;
        return std::max({left, right});
    }
};