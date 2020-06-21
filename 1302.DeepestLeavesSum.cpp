/*
Given a binary tree, return the sum of values of its deepest leaves.

Example 1:
(pic)
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
 

Constraints:
The number of nodes in the tree is between 1 and 10^4.
The value of nodes is between 1 and 100.
*/

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        std::vector<std::vector<int>> levels;
        dfs(root, 1, levels);
        return std::accumulate(levels.back().begin(), levels.back().end(), 0);
    }

private:
    void dfs(TreeNode* root, int depth, std::vector<std::vector<int>> &levels) {
        if (nullptr == root) {
            return;
        }
        if (depth > levels.size()) {
            levels.push_back(std::vector<int>());
        }
        if (nullptr == root->left && nullptr == root->right) {
            levels[depth - 1].push_back(root->val);
            return;
        }
        dfs(root->left, depth + 1, levels);
        dfs(root->right, depth + 1, levels);
    }
};