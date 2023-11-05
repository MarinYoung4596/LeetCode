/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    539.MinimumTimeDifference.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/02/11 12:51:42
*   @brief:

Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.


Example 1:
    Input: timePoints = ["23:59","00:00"]
    Output: 1

Example 2:
    Input: timePoints = ["00:00","23:59","00:00"]
    Output: 0

Constraints:
    2 <= timePoints.length <= 2 * 10^4
    timePoints[i] is in the format "HH:MM".

*****************************************************************/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> miniutes;
        for (const auto& time_point : timePoints) {
            miniutes.push_back(convert_time(time_point));
        }
        std::sort(miniutes.begin(), miniutes.end());
        const auto n = miniutes.size();
        for (auto i = 0; i < n; ++i) {
            miniutes.push_back(miniutes[i] + 24 * 60);
        }
        auto result = INT_MAX;
        for (auto i = 1; i < miniutes.size(); ++i) {
            auto diff = miniutes[i] - miniutes[i - 1];
            if (result > diff) {
                result = diff;
            }
            if (result == 0) {
                return result;
            }
        }
        return result;
    }

private:
    int convert_time(const string& clock_time) {
        auto hour = std::stoi(clock_time.substr(0, 2));
        auto miniute = std::stoi(clock_time.substr(3, 2));
        return hour * 60 + miniute;
    }
};
