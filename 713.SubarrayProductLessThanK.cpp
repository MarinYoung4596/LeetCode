/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    713.SubarrayProductLessThanK.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/30 00:53:16
*   @brief:

Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.



Example 1:
    Input: nums = [10,5,2,6], k = 100
    Output: 8
    Explanation: The 8 subarrays that have product less than 100 are:
        [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
        Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Example 2:
    Input: nums = [1,2,3], k = 0
    Output: 0


Constraints:
    1 <= nums.length <= 3 * 10^4
    1 <= nums[i] <= 1000
    0 <= k <= 10^6

*****************************************************************/


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        auto result = 0;
        auto left = 0;
        auto right = 0;
        auto product = 1;
        while (right < nums.size()) {
            product *= nums[right];
            ++right;
            while (left < right && product >= k) {
                product /= nums[left];
                ++left;
            }
            result += (right - left);
        }
        return result;
    }
};