/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    646.MaximumLengthOfPairChain.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/29 22:34:49
*   @brief:

You are given an array of n pairs pairs where pairs[i] = [left_i, right_i] and left_i < right_i.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.



Example 1:
    Input: pairs = [[1,2],[2,3],[3,4]]
    Output: 2
    Explanation: The longest chain is [1,2] -> [3,4].

Example 2:
    Input: pairs = [[1,2],[7,8],[4,5]]
    Output: 3
    Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].


Constraints:
    n == pairs.length
    1 <= n <= 1000
    -1000 <= left_i < right_i <= 1000

*****************************************************************/


class Solution {
public:
    // 最长递增子序列
    int findLongestChain(vector<vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end(), [&](const auto &lhs, const auto &rhs) {
            return lhs[0] < rhs[0];
        });
        vector<int> dp(pairs.size(), 1);
        int max_len = 1;
        for (auto i = 0; i < pairs.size(); ++i) {
            for (auto j = 0; j < i; ++j) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                max_len = max(max_len, dp[i]);
            }
        }
        return max_len;
    }
};
