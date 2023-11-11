/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    229.MajorityElementII.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/11 22:45:14
*   @brief:

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.


Example 1:
    Input: nums = [3,2,3]
    Output: [3]

Example 2:
    Input: nums = [1]
    Output: [1]

Example 3:
    Input: nums = [1,2]
    Output: [1,2]


Constraints:
    1 <= nums.length <= 5 * 10^4
    -10^9 <= nums[i] <= 10^9


Follow up: Could you solve the problem in linear time and in O(1) space?

*****************************************************************/


// First Solution: hash_map，暴力
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> num_map;
        for (auto x : nums) {
            num_map[x]++;
        }
        vector<int> result;
        for (auto [x, freq] : num_map) {
            if (freq > nums.size() / 3) {
                result.push_back(x);
            }
        }
        return result;
    }
};