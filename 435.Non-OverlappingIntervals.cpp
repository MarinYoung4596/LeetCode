/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    435.Non-OverlappingIntervals.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/22 16:27:21
*   @brief:

Given an array of intervals intervals where intervals[i] = [start_i, end_i], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.


Example 1:
    Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
    Output: 1
    Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:
    Input: intervals = [[1,2],[1,2],[1,2]]
    Output: 2
    Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:
    Input: intervals = [[1,2],[2,3]]
    Output: 0
    Explanation: You don't need to remove any of the intervals since they're already non-overlapping.


Constraints:
    1 <= intervals.length <= 10^5
    intervals[i].length == 2
    -5 * 10^4 <= start_i < end_i <= 5 * 10^4

*****************************************************************/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
            [&](const auto &lhs, const auto &rhs) {
                return lhs[1] < rhs[1];
        });
        auto pre_end = intervals[0][1];
        auto cnt = 1;
        for (auto i = 1; i < intervals.size(); ++i) {
            auto cur_begin = intervals[i][0];
            if (cur_begin >= pre_end) {
                ++cnt;
                pre_end = intervals[i][1];
            }
        }
        return intervals.size() - cnt;
    }
};

// Second Solution: 动态规划
// 相当于寻找最长非严格递增子序列的长度
class Solution2 {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
            [&](const auto &lhs, const auto &rhs) {
                return lhs[0] < rhs[0];
        });
        vector<int> dp(intervals.size(), 1);
        int max_len = 1;
        for (auto i = 1; i < intervals.size(); ++i) {
            for (auto j = 0; j < i; ++j) {
                if (intervals[j][1] <= intervals[i][0]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
                max_len = std::max(max_len, dp[i]);
            }
        }
        return intervals.size() - max_len;
    }
};