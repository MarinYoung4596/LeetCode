/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1856.MaximumSubarrayMin-Product.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/29 14:56:37
*   @brief:

The min-product of an array is equal to the minimum value in the array multiplied by the array's sum.

    For example, the array [3,2,5] (minimum value is 2) has a min-product of 2 * (3+2+5) = 2 * 10 = 20.

Given an array of integers nums, return the maximum min-product of any non-empty subarray of nums. Since the answer may be large, return it modulo 109 + 7.

Note that the min-product should be maximized before performing the modulo operation. Testcases are generated such that the maximum min-product without modulo will fit in a 64-bit signed integer.

A subarray is a contiguous part of an array.



Example 1:
    Input: nums = [1,2,3,2]
    Output: 14
    Explanation: The maximum min-product is achieved with the subarray [2,3,2] (minimum value is 2).
        2 * (2+3+2) = 2 * 7 = 14.

Example 2:
    Input: nums = [2,3,3,1,2]
    Output: 18
    Explanation: The maximum min-product is achieved with the subarray [3,3] (minimum value is 3).
        3 * (3+3) = 3 * 6 = 18.

Example 3:
    Input: nums = [3,1,5,6,4,2]
    Output: 60
    Explanation: The maximum min-product is achieved with the subarray [5,6,4] (minimum value is 4).
        4 * (5+6+4) = 4 * 15 = 60.


Constraints:
    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^7

*****************************************************************/

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    // 前缀和+单调栈
    int maxSumMinProduct(vector<int>& nums) {
        const auto n = nums.size();
        vector<uint64_t> prefix_sum(n + 1, 0);
        for (auto i = 1; i <= n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        }
        // 找到以当前数字 nums[i] 为最小值时的子数组最大长度
        vector<int> left(n, 0);  // left[i] 存储 nums[i] 往左数第一个比它小的元素下标 + 1
        stack<int> s1;
        for (auto i = 0; i < n; ++i) {
            while (!s1.empty() && nums[i] <= nums[s1.top()]) {
                s1.pop();
            }
            left[i] = s1.empty() ? 0 : s1.top() + 1;
            s1.push(i);
        }
        vector<int> right(n, 0); // right[i] 存储 nums[i] 往右数第一个比它小的元素下标 - 1
        stack<int> s2;
        for (int i = n - 1; i >= 0; --i) {
            while (!s2.empty() && nums[i] < nums[s2.top()]) {
                s2.pop();
            }
            right[i] = s2.empty() ? n - 1 : s2.top() - 1;
            s2.push(i);
        }
        uint64_t max_product = 0;
        for (auto i = 0; i < n; ++i) {
            auto range_sum = prefix_sum[right[i] + 1] - prefix_sum[left[i]];
            max_product = std::max(max_product, (range_sum * nums[i]));
        }
        uint64_t MOD = 1e9 + 7;
        return max_product % MOD;
    }
};

int main() {
    vector<int> vec1 = {1, 2, 3, 2};
    Solution obj;
    std::cout << obj.maxSumMinProduct(vec1) << std::endl;

    return 0;
}