/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    115.DistinctSubsequences.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/21 23:17:26
*   @brief:

Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.


Example 1:
    Input: s = "rabbbit", t = "rabbit"
    Output: 3
    Explanation: As shown below, there are 3 ways you can generate "rabbit" from s.
        #rabb# b #it#
        #ra# b #bbit#
        #rab# b #bit#

Example 2:
    Input: s = "babgbag", t = "bag"
    Output: 5
    Explanation: As shown below, there are 5 ways you can generate "bag" from s.
        #ba# bgba #g#
        #ba# b #g# bag
        #b# abgb #ag#
        ba #b# gb #ag#
        babg #bag#


Constraints:
    1 <= s.length, t.length <= 1000
    s and t consist of English letters.

*****************************************************************/

// First Solution: dfs / backtrack, TLE
class Solution {
public:
    int numDistinct(string s, string t) {
        int result = 0;
        backtrack(s, 0, t, 0, result);
        return result;
    }

private:
    void backtrack(const string &s, int sindex, const string &t, int tindex, int &res) {
        if (tindex == t.size()) {
            ++res;
            return;
        }
        if (sindex == s.size()) {
            return;
        }
        if ((s.size() - sindex) < (t.size() - tindex)) {  //  s长度不够，不用搜索了
            return;
        }
        if (s[sindex] != t[tindex]) {
            backtrack(s, sindex + 1, t, tindex, res);
        } else {
            // 使用当前 s[i]
            backtrack(s, sindex + 1, t, tindex + 1, res);
            // 不使用当前 s[i]
            backtrack(s, sindex + 1, t, tindex, res);
        }
    }
};

// Second Solution: dynamic programming
// 使用备忘录将已经计算的结果缓存
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> cache(s.size(), vector<int>(t.size(), -1));
        return dp(s, 0, t, 0, cache);
    }

private:
    int dp(const string &s, int sindex, const string &t, int tindex,
            vector<vector<int>> &cache) {
        if (tindex == t.size()) {
            return 1;
        }
        if (sindex == s.size()) {
            return 0;
        }
        if ((s.size() - sindex) < (t.size() - tindex)) {  //  s长度不够，不用搜索了
            return 0;
        }
        if (cache[sindex][tindex] != -1) {
            return cache[sindex][tindex];
        }
        int result = 0;
        if (s[sindex] != t[tindex]) {
            result += dp(s, sindex + 1, t, tindex, cache);
        } else {
            result += dp(s, sindex + 1, t, tindex + 1, cache); // 使用当前 s[i]
            result += dp(s, sindex + 1, t, tindex, cache); // 不使用当前 s[i]
        }
        cache[sindex][tindex] = result;
        return result;
    }
};