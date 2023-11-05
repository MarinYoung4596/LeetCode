/*****************************************************************
*   Copyright (C) 2022 All rights reserved.
*
*   @file:    485.MaxConsecutiveOnes.cpp
*   @author:  marinyoung@163.com
*   @date:    2022/12/10 17:47:57
*   @brief:

Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:
    Input: nums = [1,1,0,1,1,1]
    Output: 3
    Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Example 2:
    Input: nums = [1,0,1,1,0,1]
    Output: 2

Constraints:
    1 <= nums.length <= 10^5
    nums[i] is either 0 or 1.

*****************************************************************/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        auto res = 0;
        auto pre = 0;
        auto cur = 0;
        while (pre < nums.size()) {
            while (pre < nums.size() && nums[pre] != 1) {
                ++pre;
            }
            cur = pre;
            while (cur < nums.size() && nums[cur] != 0) {
                ++cur;
            }
            res = std::max(res, cur - pre);
            pre = cur;
        }
        return res;
    }
};
