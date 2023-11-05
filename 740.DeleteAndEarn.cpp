/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    740.DeleteAndEarn.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/13 23:54:17
*   @brief:

You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.

Return the maximum number of points you can earn by applying the above operation some number of times.


Example 1:
    Input: nums = [3,4,2]
    Output: 6
    Explanation: You can perform the following operations:
        - Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
        - Delete 2 to earn 2 points. nums = [].
        You earn a total of 6 points.

Example 2:
    Input: nums = [2,2,3,3,3,4]
    Output: 9
    Explanation: You can perform the following operations:
        - Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
        - Delete a 3 again to earn 3 points. nums = [3].
        - Delete a 3 once more to earn 3 points. nums = [].
        You earn a total of 9 points.


Constraints:
    1 <= nums.length <= 2 * 10^4
    1 <= nums[i] <= 10^4
*****************************************************************/


class Solution {
public:
    // dp[i].value = dp[i-1].value + dp[i].value * dp[i].freq     if dp[i].value - dp[i-1].value > 1
    // dp[i].value = max(dp[i-1].value, dp[i-2].value + dp[i].value * dp[i].freq)    else
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> num_freq_map;
        vector<int> dp;
        dp.push_back(0);  // 边界条件
        for (auto v : nums) {
            if (num_freq_map.count(v) > 0) {
                num_freq_map[v]++;
            } else {
                num_freq_map[v] = 1;
                dp.push_back(v);
            }
        }
        auto last_rob_money = dp[1];
        dp[1] *= num_freq_map[dp[1]];
        for (auto i = 2; i < dp.size(); ++i) {
            auto cur_money = dp[i];
            if (dp[i] - last_rob_money > 1) {
                dp[i] = dp[i - 1] + dp[i] * num_freq_map[dp[i]];
            } else {
                dp[i] = max(dp[i - 1], dp[i - 2] + dp[i] * num_freq_map[dp[i]]);
            }
            last_rob_money = cur_money;
        }
        return dp.back();
    }
};