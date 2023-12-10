/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:
    Input: [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:
    Input: [[1,4],[4,5]]
    Output: [[1,5]]
    Explanation: Intervals [1,4] and [4,5] are considered overlapping.

NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return intervals;
        }
        std::sort(intervals.begin(), intervals.end(),
                  [&](const vector<int> &lhs, const vector<int> &rhs) {
                      return lhs[0] < rhs[0];
                  });
        vector<vector<int>> result;

        int min_lower = INT_MAX;
        int max_upper = INT_MIN;
        for (const auto &pair : intervals) {
            if (pair[0] < min_lower) {
                min_lower = pair[0];
            }
            if (max_upper != INT_MIN && max_upper < pair[0]) {
                result.push_back(vector<int>({min_lower, max_upper}));
                min_lower = pair[0];
                max_upper = pair[1];
            }
            if (pair[1] > max_upper) {
                max_upper = pair[1];
            }
        }
        result.push_back(vector<int>({min_lower, max_upper}));
        return result;
    }
};