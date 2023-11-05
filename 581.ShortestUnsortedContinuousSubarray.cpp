/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    581.ShortestUnsortedContinuousSubarray.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/02 23:34:37
*   @brief:

Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.

Return the shortest such subarray and output its length.


Example 1:
    Input: nums = [2,6,4,8,10,9,15]
    Output: 5
    Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Example 2:
    Input: nums = [1,2,3,4]
    Output: 0

Example 3:
    Input: nums = [1]
    Output: 0


Constraints:
    1 <= nums.length <= 10^4
    -10^5 <= nums[i] <= 10^5


Follow up: Can you solve it in O(n) time complexity?

*****************************************************************/

#include "util.h"
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

// First Solution : 单调栈
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const auto n = nums.size();
        int left = n;  // 左边界。在此左侧，所有元素均满足递增要求
        stack<int> s1;
        for (int i = 0; i < n; ++i) {
            while (!s1.empty() && nums[i] < nums[s1.top()]) {
                left = std::min(left, s1.top());  // 不符合(递增)条件，更新左边界
                s1.pop();
            }
            s1.push(i);
        }
        int right = -1; // 右边界。在此右侧，所有元素均满足递增要求。
        stack<int> s2;
        for (int i = n - 1; i >= 0; --i) {
            while (!s2.empty() && nums[i] > nums[s2.top()]) {
                right = std::max(right, s2.top());  // 不符合（递减）条件，更新右边界
                s2.pop();
            }
            s2.push(i);
        }
        return right - left > 0 ? right - left + 1 : 0;
    }
};

// Second Solution:
class Solution2 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> ordered_nums(nums);
        std::sort(ordered_nums.begin(), ordered_nums.end());

        auto left = 0;
        while (left < nums.size() && nums[left] == ordered_nums[left]) {
            ++left;
        }
        int right = nums.size() - 1;
        while (right >= 0 && nums[right] == ordered_nums[right]) {
            --right;
        }
        return right == -1 ? 0 : right - left + 1;
    }
};

int main() {
    Solution2 obj;
    vector<int> test1 = {1};
    std::cout << obj.findUnsortedSubarray(test1) << std::endl;

    return 0;
}