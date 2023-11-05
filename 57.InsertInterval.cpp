/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    57.InsertInterval.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/05 19:43:03
*   @brief:

You are given an array of non-overlapping intervals intervals where intervals[i] = [start_i, end_i] represent the start and the end of the i_th interval and intervals is sorted in ascending order by start_i. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by start_i and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.


Example 1:
    Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
    Output: [[1,5],[6,9]]

Example 2:
    Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    Output: [[1,2],[3,10],[12,16]]
    Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


Constraints:
    0 <= intervals.length <= 10^4
    intervals[i].length == 2
    0 <= start_i <= end_i <= 10^5
    intervals is sorted by start_i in ascending order.
    newInterval.length == 2
    0 <= start <= end <= 10^5
*****************************************************************/


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        auto lower = newInterval[0];
        auto upper = newInterval[1];
        auto used = false;
        for (const auto &item : intervals) {
            auto cur_lower = item[0];
            auto cur_upper = item[1];

            if (cur_upper < lower || used) {
                result.push_back(item);
                continue;
            }
            if (upper < cur_lower) {
                result.push_back({lower, upper});
                result.push_back(item);
                used = true;
            }
            if (cur_lower <= lower && upper <= cur_upper) {
                result.push_back(item);
                used = true;
            }
            // 更新 左右下标
            if (upper <= cur_upper) {
                upper = cur_upper;
            }
            if (cur_lower <= lower) {
                lower = cur_lower;
            }
        }
        if (!used) {
            result.push_back({lower, upper});
        }
        return result;
    }
};