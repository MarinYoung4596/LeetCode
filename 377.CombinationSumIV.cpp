/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    377.CombinationSumIV.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/22 17:37:49
*   @brief:

Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.


Example 1:
    Input: nums = [1,2,3], target = 4
    Output: 7
    Explanation:
        The possible combination ways are:
        (1, 1, 1, 1)
        (1, 1, 2)
        (1, 2, 1)
        (1, 3)
        (2, 1, 1)
        (2, 2)
        (3, 1)
        Note that different sequences are counted as different combinations.

Example 2:
    Input: nums = [9], target = 3
    Output: 0


Constraints:
    1 <= nums.length <= 200
    1 <= nums[i] <= 1000
    All the elements of nums are unique.
    1 <= target <= 1000

*****************************************************************/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        const auto n = nums.size();
        std::sort(nums.begin(), nums.end());

        vector<uint32_t> dp(target + 1, 0);  // dp[i] 代表 target=i 时的组合个数
        dp[0] = 1;
        for (auto j = 1; j <= target; ++j) {
            for (auto i = 0; i < n; ++i) {  // 注意这里的顺序，i 从 0 开始代表数组可以重复使用
                if (j < nums[i]) {
                    break;
                }
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};