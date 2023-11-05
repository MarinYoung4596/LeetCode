/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    416.PartitionEqualSubsetSum.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/17 15:35:57
*   @brief:

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.


Example 1:
    Input: nums = [1,5,11,5]
    Output: true
    Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
    Input: nums = [1,2,3,5]
    Output: false
    Explanation: The array cannot be partitioned into equal sum subsets.

Constraints:
    1 <= nums.length <= 200
    1 <= nums[i] <= 100

*****************************************************************/

// First Solution: backtrack
// result: TLE
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        auto vec_sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (vec_sum % 2 == 1) {  // 数组和是奇数，肯定不行
            return false;
        }
        return backtrack(nums, 0, 0, vec_sum);
    }

private:
    bool backtrack(vector<int> &nums, int index, int cur_sum, int vec_sum) {
        if (cur_sum * 2 == vec_sum) {
            return true;
        }
        if (index >= nums.size()) {
            return false;
        }
        if (cur_sum > vec_sum / 2) {  // 都是正整数，当前和超过总和一半，提前终止
            return false;
        }
        cur_sum += nums[index];  // 选择当前元素
        auto ret1 = backtrack(nums, index + 1, cur_sum, vec_sum);
        if (ret1) {
            return true;
        }
        cur_sum -= nums[index];  // 不选择当前元素
        auto ret2 = backtrack(nums, index + 1, cur_sum, vec_sum);
        return ret2;
    }
};

// Second Solution: dp

class Solution2 {
public:
    // dp:  是否存在子数组组合，使得和为 sum/2
    // dp[i][j] 表示下标范围 0~i 区间的所有整数，能否选出一些子数组，使和为 j
    // 如果不选择下标 i 的元素：  dp[i][j] = dp[i - 1][j]
    // 反之，如果 nums[i] == j, dp[i][j] = true;
    //      如果 nums[i] < j,  dp[i][j] = dp[i][j - nums[i]]
    bool canPartition(vector<int>& nums) {
        auto vec_sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (vec_sum & 0b01) {
            return false;
        }
        auto len = nums.size();
        auto target = vec_sum / 2;
        vector<vector<bool>> dp(len + 1, vector<bool>(target + 1, false));
        for (auto i = 0; i <= len; ++i) {
            dp[i][0] = true;
        }
        for (auto i = 1; i <= len; ++i) {
            for (auto j = 1; j <= target; ++j) {
                if (j < nums[i - 1]) {  // 总和 < 上一个数组元素
                    dp[i][j] = dp[i - 1][j];
                } else {  // dp[i - 1][j] 表示不装入当前元素；dp[i-1][j - nums[i-1]] 表示装入当前元素（nums[i-1])
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[len][target];
    }
};