/*
78. subsets

Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]


*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> isSelected(nums.size(), false);
        
        dfs(result, nums, isSelected, 0);
        return result;
    }

private:
    void dfs(vector<vector<int>> &result, const vector<int> &nums, vector<bool> &selected, int step)
    {
        if (nums.size() == step)
        {
            vector<int> subset;
            for (int i = 0; i < nums.size(); ++i)
            {
                if (selected[i]) subset.push_back(nums[i]);
            }
            result.push_back(subset);
            return;
        }
        selected[step] = false;
        dfs(result, nums, selected, step + 1); // 不选 nums[step], 相同元素数目的子集 
        
        selected[step] = true;
        dfs(result, nums, selected, step + 1); // 选择 nums[step], 元素数目递增的子集
    }
};