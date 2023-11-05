/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    44.WildcardMatching.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/21 00:16:29
*   @brief:

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).


Example 1:
    Input: s = "aa", p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa".

Example 2:
    Input: s = "aa", p = "*"
    Output: true
    Explanation: '*' matches any sequence.

Example 3:
    Input: s = "cb", p = "?a"
    Output: false
    Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.


Constraints:
    0 <= s.length, p.length <= 2000
    s contains only lowercase English letters.
    p contains only lowercase English letters, '?' or '*'.

*****************************************************************/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return dfs(s, p);
    }

private:
    bool dfs(const string &s, const string &p) {
        if (p.empty()) {
            return s.empty();
        } else if (p[0] == '?') {
            return s.empty() ? \
                    false : \
                    dfs(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
        } else if (p[0] == '*') {
            if (p.size() == 1) {
                return true;
            }
            auto ret0 = dfs(s, p.substr(1, p.size() - 1)); // * 不匹配任何字符
            if (ret0) {
                return true;
            }
            if (s.empty()) {
                return false;
            }
            auto ret1 = dfs(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1)); // * 通配符 只匹配1个字符
            if (ret1) {
                return true;
            }
            auto ret2 = dfs(s.substr(1, s.size() - 1), p);  // * 通配符匹配多个字符（即到当前位置不终止）
            if (ret2) {
                return true;
            }
        } else {
            return s[0] != p[0] ? \
                    false : \
                    dfs(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
        }
    }
};


class Solution2 {
public:
    bool isMatch(string s, string p) {
        const auto slen = s.size();
        const auto plen = p.size();

        vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
        dp[0][0] = true;

        for (auto j = 1; j <= plen; ++j) {
            if (p[j - 1] == '*') {  // 这里不匹配任何字符
                dp[0][j] = true;
            } else {
                break;
            }
        }
        for (auto i = 1; i <= slen; ++i) {
            for (auto j = 1; j <= plen; ++j) {
                if (p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                } else {
                    dp[i][j] = (s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
                }
            }
        }
        return dp[slen][plen];
    }
};

int main() {
    vector<pair<string, string>> test_cases = {
        {"aa", "a"},         // 0
        {"aa", "*"},         // 1
        {"cb", "?a"},        // 0
        {"ab", "abcd"},      // 0
        {"abcd", ""},        // 0
        {"", "abcd"},        // 0
        {"", "*"},           // 1
        {"", "?"},           // 0
        {"abcd", "*cd"},     // 1
        {"adceb", "*a*b"},   // 1
        {"", "*****"},       // 1
        {"abcabczzzde", "*abc???de*"},   // 1
        {"b", "*c?b"},         // 0
        {"acdcb", "a*c?b"},      // 0
        {"babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab", "***bba**a*bbba**aab**b"}
    };
    Solution2 obj;
    for (auto &item : test_cases) {
        auto ret = obj.isMatch(item.first, item.second);
        std::cout << "s=" << item.first << " p=" << item.second \
                  << "\tmatch=" << ret << "\n";
    }

    return 0;
}