/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    862.ShortestSubarrayWithSumAtLeastK.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/12 17:50:27
*   @brief:

Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.


Example 1:
    Input: nums = [1], k = 1
    Output: 1

Example 2:
    Input: nums = [1,2], k = 4
    Output: -1

Example 3:
    Input: nums = [2,-1,2], k = 3
    Output: 3


Constraints:
    1 <= nums.length <= 10^5
    -10^5 <= nums[i] <= 10^5
    1 <= k <= 10^9

*****************************************************************/


/**
 * @brief First Solution: 前缀和数组 + 暴力遍历
 * Time Limit Exceeded
 */
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        const auto n = nums.size();
        vector<int64_t> prefix_sum(n + 1, 0);
        for (auto i = 1; i <= n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        }
        int result = INT_MAX;
        for (auto i = 0; i < n; ++i) {
            for (auto j = i + 1; j <= n; ++j) {
                auto range_sum = prefix_sum[j] - prefix_sum[i];
                if (range_sum < k) {
                    continue;
                }
                result = min(result, j - i);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};

/**
 * @brief Second Solution: 前缀和数组 + 单调队列
 */
class Solution2 {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        const auto n = nums.size();
        vector<int64_t> prefix_sum(n + 1, 0);
        for (auto i = 1; i <= n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        }
        int result = INT_MAX;
        deque<int> q;
        for (auto i = 0; i <= n; ++i) {
            auto cur_sum = prefix_sum[i];
            while (!q.empty() && cur_sum - prefix_sum[q.front()] >= k) {  // 满足要求
                result = min(result, i - q.front());
                q.pop_front();  // 因为 此后满足要求的子数组，长度均大于以 当前front 为起始位置的子数组
            }
            while (!q.empty() && prefix_sum[q.back()] >= cur_sum) {
                q.pop_back();  // 因为存储在 q中的数都是 减数（而非被减数），因此 更大的数使得，>=k 的条件更难满足
            }
            q.push_back(i);
        }
        return result == INT_MAX ? -1 : result;
    }
};