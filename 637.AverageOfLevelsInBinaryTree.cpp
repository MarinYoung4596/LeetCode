/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.


Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].


Note:
The range of node's value is in the range of 32-bit signed integer.
*/

// First Solution: 会溢出：[2147483647,2147483647,2147483647]
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        std::vector<std::vector<int>> levels;
        dfs(root, 1, levels);

        std::vector<double> result;
        for (const auto &level : levels) {
            double sum = std::accumulate(level.begin(), level.end(), 0.0);
            result.push_back(static_cast<double>(sum) / level.size());
        }
        return result;
    }

private:
    void dfs(TreeNode* root,
             int level,
             std::vector<std::vector<int>> &levels) {
        if (nullptr == root) {
            return;
        }
        if (level > levels.size()) {
            levels.push_back(std::vector<int>());
        }
        levels[level - 1].push_back(root->val);
        dfs(root->left, level + 1, levels);
        dfs(root->right, level + 1, levels);
    }
};