/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    907.SumOfSubarrayMinimums.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/28 23:30:24
*   @brief:

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.
Since the answer may be large, return the answer modulo `10^9 + 7`.


Example 1:
    Input: arr = [3,1,2,4]
    Output: 17
    Explanation:
        Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
        Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
        Sum is 17.

Example 2:
    Input: arr = [11,81,94,43,3]
    Output: 444


Constraints:
    1 <= arr.length <= 3 * 10^4
    1 <= arr[i] <= 3 * 10^4

*****************************************************************/

#include <vector>
#include <iostream>

using namespace std;

// First Solution : 暴力解法, 时间复杂度 O(N^2)
// Time Limit Exceeded
class Solution {
public:
    // 转换成：以每个元素为最小元素 * 以该元素为最小元素的子数组数量
    // 以该元素为最小元素的子数组数量: 该元素左侧以该元素为最小元素的子数组数量 * 该元素右侧以该元素为最小元素的子数组数量
    int sumSubarrayMins(vector<int>& arr) {
        const auto n = arr.size();
        vector<int> left(n, 0); // 表示 arr[0]~arr[i] 里以 arr[i] 为最小元素的子数组数量
        for (auto i = 0; i < n; ++i) {
            if (i == 0) {
                left[i] = 1;
            } else {
                auto idx = i - 1;
                while (idx >= 0 && arr[idx] > arr[i]) {
                    --idx;
                }
                left[i] = i - idx;  // 表示从 idx~i 区间构成的子数组数量
            }
        }
        vector<int> right(n, 0); // 表示 arr[i]~arr[n-1] 里 以arr[i] 为最小元素的子数组数量
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                right[i] = 1;
            } else {
                auto idx = i + 1;
                while (idx < n && arr[idx] >= arr[i]) {  // 相等时，为了减少重复计算，上面 left 不考虑相等；这里 right 考虑相等
                    ++idx;
                }
                right[i] = idx - i;
            }
        }
        uint64_t result = 0;
        uint64_t MOD = 1e9 + 7;
        for (auto i = 0; i < n; ++i) {
            uint64_t cur_min_sum = left[i] * right[i] * arr[i];
            uint64_t cur_res = (result + cur_min_sum) % MOD;
            result = cur_res;
        }
        return result;
    }
};

// Second Solution:
// 上述思路的改进，使用单调栈，降低搜索次数，时间复杂度：O(N)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const auto n = arr.size();
        vector<int> left(n, 0); // 表示 arr[0]~arr[i] 里以 arr[i] 为最小元素的子数组数量
        stack<int> s1;
        for (auto i = 0; i < n; ++i) {
            while (!s1.empty() && arr[i] <= arr[s1.top()]) {
                s1.pop();
            }
            left[i] = s1.empty() ? i + 1 : i - s1.top();
            s1.push(i);
        }
        vector<int> right(n, 0); // 表示 arr[i]~arr[n-1] 里 以arr[i] 为最小元素的子数组数量
        stack<int> s2;
        for (int i = n - 1; i >= 0; --i) {
            while (!s2.empty() && arr[i] < arr[s2.top()]) {
                s2.pop();
            }
            right[i] = s2.empty() ? n - i : s2.top() - i;
            s2.push(i);
        }
        uint64_t result = 0;
        uint64_t MOD = 1e9 + 7;
        for (auto i = 0; i < n; ++i) {
            uint64_t cur_min_sum = static_cast<uint64_t>(left[i]) * right[i] * arr[i];
            uint64_t cur_res = (result + cur_min_sum) % MOD;
            result = cur_res;
        }
        return result;
    }
};


int main() {
    vector<int> vec = {11,81,94,43,3};
    Solution obj;
    cout << obj.sumSubarrayMins(vec) << endl;
    return 0;
}