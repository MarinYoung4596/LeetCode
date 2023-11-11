/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1979.FindGreatestCommonDivisorOfArray.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/11 18:33:21
*   @brief:

Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.


Example 1:
    Input: nums = [2,5,6,9,10]
    Output: 2
    Explanation:
        The smallest number in nums is 2.
        The largest number in nums is 10.
        The greatest common divisor of 2 and 10 is 2.

Example 2:
    Input: nums = [7,5,6,8,3]
    Output: 1
    Explanation:
        The smallest number in nums is 3.
        The largest number in nums is 8.
        The greatest common divisor of 3 and 8 is 1.

Example 3:
    Input: nums = [3,3]
    Output: 3
    Explanation:
        The smallest number in nums is 3.
        The largest number in nums is 3.
        The greatest common divisor of 3 and 3 is 3.


Constraints:
    2 <= nums.length <= 1000
    1 <= nums[i] <= 1000

*****************************************************************/


class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto max_val = INT_MIN;
        auto min_val = INT_MAX;
        for (auto x : nums) {
            max_val = max(max_val, x);
            min_val = min(min_val, x);
        }
        return gcd(max_val, min_val);
    }
};