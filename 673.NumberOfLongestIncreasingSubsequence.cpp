/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    673.NumberOfLongestIncreasingSubsequence.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/21 14:29:12
*   @brief:

Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.



Example 1:
    Input: nums = [1,3,5,4,7]
    Output: 2
    Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:
    Input: nums = [2,2,2,2,2]
    Output: 5
    Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.


Constraints:
    1 <= nums.length <= 2000
    -10^6 <= nums[i] <= 10^6

*****************************************************************/

// First Solution: dfs: Time Limit Exceeded
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> bucket(nums.size() + 1, 0);

        dfs(nums, 0, INT_MIN, 0, bucket);

        auto idx = bucket.size() - 1;
        while (idx >= 0 && bucket[idx] == 0) {
            --idx;
        }
        return bucket[idx];
    }

private:
    void dfs(const vector<int> &nums, int index,
             int pre_val, int cur_len,
             vector<int> &bucket) {
        if (index > nums.size()) {
            return;
        }
        if (index == nums.size()) {
            bucket[cur_len]++;
            return;
        }
        if (nums[index] > pre_val) {
            dfs(nums, index + 1, nums[index], cur_len + 1, bucket);  // 选
            dfs(nums, index + 1, pre_val, cur_len, bucket); // 不选
        } else {
            dfs(nums, index + 1, pre_val, cur_len, bucket); // 不选
        }
    }
};

// second solution: dynamic programming
class Solution2 {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const auto n = nums.size();
        vector<int> dp(n, 1);   // dp[i]  表示以 nums[i] 为结尾的数组 的最长递增子序列长度。最差情况下长度也应该是1
        vector<int> cnt(n, 1);  // cnt[i] 表示以 nums[i] 为结尾的数组 的最长递增子序列个数。

        auto max_len = 0;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < i; ++j) {
                if (nums[j] >= nums[i]) {
                    continue;
                }
                // 此时，dp[i] = dp[j] + 1
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;      // 最大长度变了
                    cnt[i] = cnt[j];        // 因此频次重新计数
                } else if (dp[j] + 1 == dp[i]) {
                    cnt[i] += cnt[j];       // 最大长度未变，因此频次累加
                }
            }
            max_len = max(max_len, dp[i]);  // 记录当前最大长度
        }
        auto result = 0;
        for (auto i = 0; i < n; ++i) {
            if (dp[i] == max_len) {
                result += cnt[i];
            }
        }
        return result;
    }
};
