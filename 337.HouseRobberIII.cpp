/*

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.


Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        std::unordered_map<TreeNode*, int> dp;
        return rob_helper(root, dp);
    }

private:
    int rob_helper(TreeNode* root, std::unordered_map<TreeNode*, int> &dp) {
        if (root == nullptr) {
            return 0;
        }
        if (dp.count(root) > 0) {
            return dp[root];
        }
        // 选当前root，当前root值+左右孙子结果相加
        int rob_left = root->left == nullptr ? 0 : \
            rob_helper(root->left->left, dp) + rob_helper(root->left->right, dp);
        int rob_right = root->right == nullptr ? 0 : \
            rob_helper(root->right->left, dp) + rob_helper(root->right->right, dp);
        int rob_res = root->val + rob_left + rob_right;

        // 不选当前root, 左右儿子结果相加
        int not_rob_res = rob_helper(root->left, dp) + rob_helper(root->right, dp);

        // 取最大
        int cur_res = std::max(rob_res, not_rob_res);
        // 缓存
        dp[root] = cur_res;
        return cur_res;
    }
};