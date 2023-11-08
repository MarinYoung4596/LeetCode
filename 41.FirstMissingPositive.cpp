/*****************************************************************
*   Copyright (C) 2023 Baidu.com, Inc. All rights reserved.
*
*   @file:    41.FirstMissingPositive.cpp
*   @author:  yangnan09@baidu.com
*   @date:    2023/11/07 11:26:47
*   @brief:

Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.



Example 1:
    Input: nums = [1,2,0]
    Output: 3
    Explanation: The numbers in the range [1,2] are all in the array.

Example 2:
    Input: nums = [3,4,-1,1]
    Output: 2
    Explanation: 1 is in the array but 2 is missing.

Example 3:
    Input: nums = [7,8,9,11,12]
    Output: 1
    Explanation: The smallest positive integer 1 is missing.


Constraints:
    1 <= nums.length <= 10^5
    -2^31 <= nums[i] <= 2^31 - 1

*****************************************************************/

// First Solution: 暴力
// 时间复杂度：O(NlogN)；空间复杂度：O(N)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> num_set;
        vector<int> pos_nums;
        for (auto x : nums) {
            if (x <= 0 || num_set.count(x) > 0) {
                continue;
            }
            pos_nums.push_back(x); // 保留正数
            num_set.insert(x);  // 去重
        }
        std::sort(pos_nums.begin(), pos_nums.end());
        for (auto i = 0; i < pos_nums.size(); ++i) {
            if (pos_nums[i] > i + 1) {
                return i + 1;
            }
        }
        return pos_nums.size() + 1;
    }
};
