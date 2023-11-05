/**
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sum_helper(root, false);
    }

private:
    int sum_helper(TreeNode *root, bool is_left_leaf) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return static_cast<int>(is_left_leaf) * root->val;
        }
        int result = 0;
        result += sum_helper(root->left, true);
        result += sum_helper(root->right, false);
        return result;
    }
};