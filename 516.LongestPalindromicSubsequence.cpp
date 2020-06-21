/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".


Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".

*/

class Solution {
public:
    // if s[i] == s[j], s[i][j] = s[i+1][j-1] + 2
    // else  s[i][j] = max(dp[i+1][j], dp[i][j-1])
    int longestPalindromeSubseq(string s) {
        const int n = s.size();
        if (n < 2) { return n; }
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        for (auto j = 0; j < n; ++j) { // 对角线，元素本身
            dp[j][j] = 1;
        }
        for (auto i = n - 1; i >= 0; --i) { // 因为i+1, 所以i是从后往前遍历
            for (auto j = i + 1; j < n; ++j) { // 观察规律，因为j-1, 所以j是从前往后遍历
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
