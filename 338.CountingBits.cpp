/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    338.CountingBits.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/22 15:31:05
*   @brief:

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.


Example 1:
    Input: n = 2
    Output: [0,1,1]
    Explanation:
        0 --> 0
        1 --> 1
        2 --> 10

Example 2:
    Input: n = 5
    Output: [0,1,1,2,1,2]
    Explanation:
        0 --> 0
        1 --> 1
        2 --> 10
        3 --> 11
        4 --> 100
        5 --> 101


Constraints:
    0 <= n <= 10^5


Follow up:
    It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
    Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?

*****************************************************************/

// First Solution:
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        for (auto i = 1; i <= n; ++i) {
            auto pre_key = i - lowbit(i);
            result[i] += (result[pre_key] + 1);
        }
        return result;
    }

private:
    int lowbit(int x) {  // 树状数组
        return x & (-x);
    }
};