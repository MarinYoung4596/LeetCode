/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    414.ThirdMaximumNumber.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/15 12:24:15
*   @brief:

Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.


Example 1:
    Input: nums = [3,2,1]
    Output: 1
    Explanation:
        The first distinct maximum is 3.
        The second distinct maximum is 2.
        The third distinct maximum is 1.

Example 2:
    Input: nums = [1,2]
    Output: 2
    Explanation:
        The first distinct maximum is 2.
        The second distinct maximum is 1.
        The third distinct maximum does not exist, so the maximum (2) is returned instead.

Example 3:
    Input: nums = [2,2,3,1]
    Output: 1
    Explanation:
        The first distinct maximum is 3.
        The second distinct maximum is 2 (both 2's are counted together since they have the same value).
        The third distinct maximum is 1.


Constraints:
    1 <= nums.length <= 10^4
    -2^31 <= nums[i] <= 2^31 - 1


Follow up: Can you find an O(n) solution?

*****************************************************************/


// First Solution: Sort
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::greater<>());
        int diff = 1;
        for (auto i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                ++diff;
            }
            if (diff == 3) {
                return nums[i];
            }
        }
        return nums[0];
    }
};

// Second Solution: 迭代法
class Solution2 {
public:
    int thirdMax(vector<int>& nums) {
        long first_max = LONG_MIN;
        long second_max = LONG_MIN;
        long third_max = LONG_MIN;
        for (long x : nums) {
            if (x > first_max) {
                third_max = second_max;
                second_max = first_max;
                first_max = x;
            } else if (first_max > x && x > second_max) { // 防止等于的情况
                third_max = second_max;
                second_max = x;
            } else if (second_max > x && x > third_max) {
                third_max = x;
            } else {
                continue;
            }
        }
        return third_max == LONG_MIN ? first_max : third_max;
    }
};