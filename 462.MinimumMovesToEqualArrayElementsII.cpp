/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    462.MinimumMovesToEqualArrayElementsII.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/11 23:24:06
*   @brief:

Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.


Example 1:
    Input: nums = [1,2,3]
    Output: 2
    Explanation: Only two moves are needed (remember each move increments or decrements one element):
        [1,2,3]  =>  [2,2,3]  =>  [2,2,2]

Example 2:
    Input: nums = [1,10,2,9]
    Output: 16


Constraints:
    n == nums.length
    1 <= nums.length <= 10^5
    -10^9 <= nums[i] <= 10^9

*****************************************************************/


class Solution {
public:
    // 都移动到中位数（而非均值）
    int minMoves2(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        const auto n = nums.size();
        int median = n % 2 == 0 ? \
                (nums[n / 2 - 1] + nums[n / 2]) / 2 : \
                nums[(n - 1) / 2];
        int result = 0;
        for (auto x : nums) {
            result += abs(x - median);
        }
        return result;
    }
};