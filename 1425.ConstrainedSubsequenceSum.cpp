/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1425.ConstrainedSubsequenceSum.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/11 16:11:55
*   @brief:

Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.


Example 1:
    Input: nums = [10,2,-10,5,20], k = 2
    Output: 37
    Explanation: The subsequence is [10, 2, 5, 20].

Example 2:
    Input: nums = [-1,-2,-3], k = 1
    Output: -1
    Explanation: The subsequence must be non-empty, so we choose the largest number.

Example 3:
    Input: nums = [10,-2,-10,-5,20], k = 2
    Output: 23
    Explanation: The subsequence is [10, -2, -5, 20].


Constraints:
    1 <= k <= nums.length <= 10^5
    -10^4 <= nums[i] <= 10^4

*****************************************************************/

/**
 *  First Solution: dp
 *  Time Complexity: O(kn) ~ O(n^2)
 *  space Complexity: O(n)
 *  Time Limit Exceeded
 */
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int max_sum = INT_MIN;
        const auto n = nums.size();
        vector<int> dp(nums);  // dp[i] 代表到 0~i 位置的子数组中，符合条件的最大子序列和
        for (int i = 0; i < n; ++i) {
            for (int j = max(0, i - k); j < i; ++j) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
            max_sum = max(max_sum, dp[i]);
        }
        return max_sum;
    }
};


/**
 * Second Solution: dp + 单调队列
 */
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int max_sum = nums[0];
        vector<int> dp(nums);  // 初始时，dp[i] 代表只使用当前一个元素的子序列和

        deque<int> window; // 单调栈，目的是 保留 k-i ~ i 范围内，和最大子序列
        window.push_back(0);
        for (auto i = 1; i < nums.size(); ++i) {
            while (!window.empty() && window.front() < i - k) {  // 距离大于 k，不满足要求
                window.pop_front();
            }

            dp[i] = max(dp[i], dp[window.front()] + nums[i]);  // 不用之前的序列 ：用之前的序列，取 max
            max_sum = max(max_sum, dp[i]);

            while (!window.empty() && dp[window.back()] < dp[i]) { // 所有小于当前子序列和的子序列都 pop，降低计算开销
                window.pop_back();
            }
            window.push_back(i);
        }
        return max_sum;
    }
};