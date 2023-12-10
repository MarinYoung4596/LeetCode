/*
113. Path Sum II

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
    Given the below binary tree and sum = 22,
          5
         / \
        4   8
       /   / \
      11  13 4
    /   \   / \
   7    2  5   1
    return
    [
        [5,4,11,2],
        [5,8,4,5]
    ]
*/

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> candidates;
        backtrack(root, targetSum, candidates, result);
        return result;
    }

private:
    void backtrack(TreeNode* root, int target_sum,
                   vector<int> &candidates,
                   vector<vector<int>> &result) {
        if (nullptr == root) {
            return;
        }
        target_sum -= root->val;
        candidates.push_back(root->val);
        if (nullptr == root->left && nullptr == root->right) {
            if (target_sum == 0) {
                result.push_back(candidates);
            }
        }
        dfs(root->left, target_sum, candidates, result);
        dfs(root->right, target_sum, candidates, result);
        candidates.pop_back(); // 不选当前节点
    }
};
