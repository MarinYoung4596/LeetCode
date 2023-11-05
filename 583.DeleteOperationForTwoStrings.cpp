/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    583.DeleteOperationForTwoStrings.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/05 23:05:49
*   @brief:

Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.


Example 1:
    Input: word1 = "sea", word2 = "eat"
    Output: 2
    Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Example 2:
    Input: word1 = "leetcode", word2 = "etco"
    Output: 4


Constraints:
    1 <= word1.length, word2.length <= 500
    word1 and word2 consist of only lowercase English letters.

*****************************************************************/


class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1,
                                vector<int>(word2.size() + 1, 0));

        // 边界：第一行第一列
        dp[0][0] = word1[0] == word2[0] ? 0 : 2;
        // 边界：第一列
        for (auto i = 1; i < word1.size(); ++i) {
            dp[i][0] = word1[i] == word2[0] ? i : dp[i - 1][0] + 1;
        }
        // 边界：第一行
        for (auto j = 1; j < word2.size(); ++j) {
            dp[0][j] = word1[0] == word2[j] ? j : dp[0][j - 1] + 1;
        }
        for (auto i = 1; i < word1.size(); ++i) {
            for (auto j = 1; j < word2.size(); ++j) {
                dp[i][j] = word1[i] == word2[j] ? \
                            dp[i - 1][j - 1] : \
                            std::min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
        return dp[word1.size() - 1][word2.size() - 1];
    }
};