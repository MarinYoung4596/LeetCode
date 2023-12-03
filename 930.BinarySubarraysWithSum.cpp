/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    930.BinarySubarraysWithSum.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/12/03 20:02:22
*   @brief:

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.


Example 1:
    Input: nums = [1,0,1,0,1], goal = 2
    Output: 4
    Explanation: The 4 subarrays are bolded and underlined below:
        [#1,0,1#,0,1]
        [#1,0,1,0#,1]
        [1,#0,1,0,1#]
        [1,0,#1,0,1#]

Example 2:
    Input: nums = [0,0,0,0,0], goal = 0
    Output: 15


Constraints:
    1 <= nums.length <= 3 * 10^4
    nums[i] is either 0 or 1.
    0 <= goal <= nums.length

*****************************************************************/

/**
 * @brief First Solution: 前缀和
 * 时间复杂度：O(N^2)
 * Time Limit Exceeded
 */
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        const auto n = nums.size();
        vector<int> prefix_sum(n + 1, 0);
        for (auto i = 1; i <= n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        }
        auto result = 0;
        for (auto i = 0; i < n; ++i) {
            for (auto j = i + 1; j <= n; ++j) {
                if (prefix_sum[j] - prefix_sum[i] == goal) {
                    ++result;
                }
            }
        }
        return result;
    }
};

/**
 * @brief Second Solution: 前缀和 + hash_map
 */
class Solution2 {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        auto result = 0;
        unordered_map<int, int> prefix_sum_map;
        prefix_sum_map[0] = 1; // 表示当前前缀和刚好 == goal
        auto prefix_sum = 0;
        for (auto x : nums) {
            prefix_sum += x;
            if (prefix_sum_map.count(prefix_sum - goal) > 0) {
                result += prefix_sum_map[prefix_sum - goal];
            }
            prefix_sum_map[prefix_sum]++;
        }
        return result;
    }
};

/**
 * @brief Second Solution: 滑动窗口
 * 注意：这里并非
 */
class Solution3 {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        auto result = 0;
        auto left = 0;
        auto right = 0;
        auto cur_sum = 0;
        while (right < nums.size()) {
            cur_sum += nums[right];
            ++right;

            while (left < right && cur_sum > goal) { // 窗口收缩，直至cur_sum==goal 或 left==right
                cur_sum -= nums[left];
                ++left;
            }
            auto saved_sum = cur_sum;  // 保存当前的窗口和: [left, right)
            auto t = left;
            while (t < right && cur_sum == goal) { // 临时收缩窗口，实际窗口并不收缩
                ++result;
                cur_sum -= nums[t];
                ++t;
            }
            cur_sum = saved_sum; // 恢复窗口和
        }
        return result;
    }
};
