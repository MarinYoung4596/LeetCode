/*
Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
    Input: "abc"
    Output: 3
    Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
    Input: "aaa"
    Output: 6
    Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


Note:
    The input string length won't exceed 1000.
*/


class Solution {
public:
    // dp[i][j] 表示i~j 是否为回文串
    int countSubstrings(string s) {
        const auto N = s.size();
        std::vector<std::vector<bool>> dp(N, std::vector<bool>(N, false));

        int result = 0;
        for (int i = N - 1; i >= 0; --i) {
            for (int j = i; j < N; ++j) {
                if (j == i) {
                    dp[i][j] = true;
                    ++result;
                    continue;
                }
                if (s[i] == s[j] && (i + 1 == j || dp[i + 1][j - 1])) {
                    // i+1 == j 时，dp[i+1][j-1] = dp[j][i], 同样未知
                    dp[i][j] = true;
                    ++result;
                }
            }
        }
        return result;
    }
};