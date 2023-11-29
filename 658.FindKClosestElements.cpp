/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    658.FindKClosestElements.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/29 00:07:46
*   @brief:

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:
    |a - x| < |b - x|, or
    |a - x| == |b - x| and a < b


Example 1:
    Input: arr = [1,2,3,4,5], k = 4, x = 3
    Output: [1,2,3,4]

Example 2:
    Input: arr = [1,2,3,4,5], k = 4, x = -1
    Output: [1,2,3,4]


Constraints:
    1 <= k <= arr.length
    1 <= arr.length <= 10^4
    arr is sorted in ascending order.
    -10^4 <= arr[i], x <= 10^4

*****************************************************************/


// First Solution：暴力
class Solution {
public:
    using int_pair = std::pair<int, int>;  // value, delta

    static bool cmp(const int_pair &lhs, const int_pair &rhs) {
        if (lhs.second != rhs.second) {
            return lhs.second < rhs.second;
        } else {
            return lhs.first < rhs.first;
        }
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int_pair> res1;
        for (auto i = 0; i < arr.size(); ++i) {
            res1.push_back(std::make_pair(arr[i], abs(arr[i] - x)));
        }
        std::sort(res1.begin(), res1.end(), cmp);
        vector<int> res2;
        for (auto i = 0; i < res1.size() && i < k; ++i) {
            res2.push_back(res1[i].first);
        }
        std::sort(res2.begin(), res2.end());
        return res2;
    }
};