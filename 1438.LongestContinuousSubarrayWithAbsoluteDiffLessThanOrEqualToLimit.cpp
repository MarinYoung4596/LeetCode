/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1438.LongestContinuousSubarrayWithAbsoluteDiffLessThanOrEqualToLimit.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/27 23:34:58
*   @brief:

Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.


Example 1:
    Input: nums = [8,2,4,7], limit = 4
    Output: 2
    Explanation: All subarrays are:
        [8] with maximum absolute diff |8-8| = 0 <= 4.
        [8,2] with maximum absolute diff |8-2| = 6 > 4.
        [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
        [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
        [2] with maximum absolute diff |2-2| = 0 <= 4.
        [2,4] with maximum absolute diff |2-4| = 2 <= 4.
        [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
        [4] with maximum absolute diff |4-4| = 0 <= 4.
        [4,7] with maximum absolute diff |4-7| = 3 <= 4.
        [7] with maximum absolute diff |7-7| = 0 <= 4.
        Therefore, the size of the longest subarray is 2.

Example 2:
    Input: nums = [10,1,2,4,7,2], limit = 5
    Output: 4
    Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.

Example 3:
    Input: nums = [4,2,2,2,4,4,2,2], limit = 0
    Output: 3


Constraints:
    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^9
    0 <= limit <= 10^9


Hints:
    Use a sliding window approach keeping the maximum and minimum value using a data structure like a multiset from STL in C++.
    More specifically, use the two pointer technique, moving the right pointer as far as possible to the right until the subarray is not valid (maxValue - minValue > limit), then moving the left pointer until the subarray is valid again (maxValue - minValue <= limit). Keep repeating this process.

*****************************************************************/


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0;
        int right = 0;

        deque<int> max_queue; // 单调递增
        deque<int> min_queue; // 单调递减

        auto max_len = INT_MIN;
        while (right < nums.size()) {
            // 维护单调队列
            while (!max_queue.empty() && max_queue.back() < nums[right]) {
                max_queue.pop_back();
            }
            max_queue.push_back(nums[right]);
            while (!min_queue.empty() && min_queue.back() > nums[right]) {
                min_queue.pop_back();
            }
            min_queue.push_back(nums[right]);
            // 窗口收缩
            while (!max_queue.empty() && !min_queue.empty()
                    && max_queue.front() - min_queue.front() > limit) {
                if (nums[left] == max_queue.front()) {
                    max_queue.pop_front();
                }
                if (nums[left] == min_queue.front()) {
                    min_queue.pop_front();
                }
                ++left;
            }
            // 满足条件
            auto cur_len = right - left + 1;
            max_len = max(max_len, cur_len);

            ++right;
        }
        return max_len;
    }
};