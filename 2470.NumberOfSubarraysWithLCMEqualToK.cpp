/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    2470.NumberOfSubarraysWithLCMEqualToK.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/11 22:24:36
*   @brief:

Given an integer array nums and an integer k, return the number of subarrays of nums where the least common multiple of the subarray's elements is k.

A subarray is a contiguous non-empty sequence of elements within an array.

The least common multiple of an array is the smallest positive integer that is divisible by all the array elements.


Example 1:
    Input: nums = [3,6,2,7,1], k = 6
    Output: 4
    Explanation: The subarrays of nums where 6 is the least common multiple of all the subarray's elements are:
        - [3,6,2,7,1]
        - [3,6,2,7,1]
        - [3,6,2,7,1]
        - [3,6,2,7,1]

Example 2:
    Input: nums = [3], k = 2
    Output: 0
    Explanation: There are no subarrays of nums where 2 is the least common multiple of all the subarray's elements.


Constraints:
    1 <= nums.length <= 1000
    1 <= nums[i], k <= 1000

*****************************************************************/


// First Solution: 暴力
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int result = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            auto tmp = 1;
            for (auto j = i; j < nums.size(); ++j) {
                tmp = lcm(tmp, nums[j]);
                if (tmp == k) {
                    ++result;
                } else if (tmp > k) {
                    break;
                }
            }
        }
        return result;
    }
};