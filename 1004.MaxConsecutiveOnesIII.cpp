/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1004.MaxConsecutiveOnesIII.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/29 00:21:27
*   @brief:

Given a binary array nums and an integer k,

return the maximum number of consecutive 1's in the array if you can flip at most k 0's.


Example 1:
    Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2

    Output: 6
    Explanation: [1,1,1,0,0,1,1,1,1,1,1]
                            ↑ - - - - ↑
        Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:
    Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
    Output: 10
    Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
                      - - ↑ ↑ - - - ↑ - -
        Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


Constraints:
    1 <= nums.length <= 10^5
    nums[i] is either 0 or 1.
    0 <= k <= nums.length

*****************************************************************/


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        auto max_len = 0;
        auto left = 0;
        auto right = 0;
        auto zero_cnt = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) {
                zero_cnt++;
            }
            ++right;

            while (left < right && zero_cnt > k) {
                if (nums[left] == 0) {
                    zero_cnt--;
                }
                ++left;
            }
            max_len = max(max_len, right - left);
        }
        return max_len;
    }
};