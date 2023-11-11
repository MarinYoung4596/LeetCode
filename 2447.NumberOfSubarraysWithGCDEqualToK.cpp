/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    2447.NumberOfSubarraysWithGCDEqualToK.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/11 22:27:23
*   @brief:

Given an integer array nums and an integer k, return the number of subarrays of nums where the greatest common divisor of the subarray's elements is k.

A subarray is a contiguous non-empty sequence of elements within an array.

The greatest common divisor of an array is the largest integer that evenly divides all the array elements.


Example 1:
    Input: nums = [9,3,1,2,6,3], k = 3
    Output: 4
    Explanation: The subarrays of nums where 3 is the greatest common divisor of all the subarray's elements are:
        - [9,3,1,2,6,3]
        - [9,3,1,2,6,3]
        - [9,3,1,2,6,3]
        - [9,3,1,2,6,3]

Example 2:
    Input: nums = [4], k = 7
    Output: 0
    Explanation: There are no subarrays of nums where 7 is the greatest common divisor of all the subarray's elements.


Constraints:
    1 <= nums.length <= 1000
    1 <= nums[i], k <= 10^9

*****************************************************************/

class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int result = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            auto tmp = nums[i];
            for (auto j = i; j < nums.size(); ++j) {
                tmp = gcd(tmp, nums[j]);
                if (tmp == k) {
                    ++result;
                } else if (tmp < k) {
                    break;
                }
            }
        }
        return result;
    }
};