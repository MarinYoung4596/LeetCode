/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root."

Besides the root, each house has one and only one parent house.
After a tour, the smart thief realized that "all houses in this place forms a binary tree".
It will automatically contact the police if two directly-linked houses were broken into on the same night.

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


Constraints:
    The number of nodes in the tree is in the range [1, 10^4].
    0 <= Node.val <= 10^4
*/


class Solution {
public:
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
        auto rob_res = root->val;
        if (root->left != nullptr) {
            rob_res += rob_helper(root->left->left, dp);
            rob_res += rob_helper(root->left->right, dp);
        }
        if (root->right != nullptr) {
            rob_res += rob_helper(root->right->left, dp);
            rob_res += rob_helper(root->right->right, dp);
        }

        // 不选当前root, 左右儿子结果相加
        int not_rob_res = rob_helper(root->left, dp) + rob_helper(root->right, dp);

        // 取最大 并缓存
        dp[root] = std::max(rob_res, not_rob_res);
        return dp[root];
    }
};