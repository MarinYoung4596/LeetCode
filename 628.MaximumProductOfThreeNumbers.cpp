/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    628.MaximumProductOfThreeNumbers.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/11 23:02:35
*   @brief:

Given an integer array nums, find three numbers whose product is maximum and return the maximum product.


Example 1:
    Input: nums = [1,2,3]
    Output: 6

Example 2:
    Input: nums = [1,2,3,4]
    Output: 24

Example 3:
    Input: nums = [-1,-2,-3]
    Output: -6


Constraints:
    3 <= nums.length <= 10^4
    -1000 <= nums[i] <= 1000

*****************************************************************/


class Solution {
public:
    // 找到最大、最小的三个数；
    // 这里偷懒用了 sort，时间复杂度 O(NlogN)
    // 还可以遍历，时间复杂度降到 O(N)
    int maximumProduct(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        const auto n = nums.size();
        return std::max(nums[n - 1] * nums[n - 2] * nums[n - 3],  // 没有负数
                        nums[n - 1] * nums[0] * nums[1]);  // 有负数
    }
};