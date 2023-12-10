/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input:
    5
   / \
  3   6
 / \   \
2   4   7
Target = 9
Output: True


Example 2:
Input:
    5
   / \
  3   6
 / \   \
2   4   7
Target = 28
Output: False
*/

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> targets;
        return dfs(root, k, targets);
    }

private:
    bool dfs(TreeNode* root, int k, unordered_set<int> &targets) {
        if (root == nullptr) {
            return false;
        }
        if (targets.count(root->val) > 0) {
            return true;
        }
        targets.insert(k - root->val);
        auto left_res = dfs(root->left, k, targets);
        auto right_res = dfs(root->right, k, targets);
        return left_res || right_res;
    }
};
