/*


Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
    Given:
        s1 = "aabcc",
        s2 = "dbbca",
    When s3 = "aadbbcbcac", return true.
    When s3 = "aadbbbaccc", return false.

*/
// Time Limit Exceeded
class Solution {
public:
    // 从后往前
    bool isInterleave(string &s1, string &s2, string &s3) {
        if (s3.size() != (s1.size() + s2.size())) {
            return false;
        }
        return dfs(s1, s1.size()-1, s2, s2.size()-1, s3, s3.size()-1);
    }

private:
    bool dfs(string &s1, int i, string &s2, int j, string &s3, int k) {
        if (k == -1) {
            return true;
        }
        if (i == -1) {
            return s2[j] != s3[k] ? false : dfs(s1, -1, s2, j-1, s3, k-1);
        }
        if (j == -1) {
            return s1[i] != s3[k] ? false : dfs(s1, i-1, s2, -1, s3, k-1);
        }

        if (s3[k] == s1[i] && s3[k] == s2[j]) {
            return dfs(s1, i-1, s2, j, s3, k-1) || dfs(s1, i, s2, j-1, s3, k-1);
        }
        if (s3[k] == s1[i]) {
            return dfs(s1, i-1, s2, j, s3, k-1);  // s3[k] != s2[j]
        }
        if (s3[k] == s2[j]) {
            return dfs(s1, i, s2, j-1, s3, k-1);  // s3[k] != s1[i]
        }
        return false; // s3[k] != s1[i] && s3[k] != s2[j]
    }
};

// Second Solution: dp
class Solution2 {
public:
    // dp[i][j] : s1[0...i] s2[0...j] 能否构成 s3[0...(i+j)]
    bool isInterleave(string &s1, string &s2, string &s3) {
        if (s3.size() != (s1.size() + s2.size())) {
            return false;
        }

        const auto m = s1.size();
        const auto n = s2.size();

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (auto i = 1; i <= m; ++i) {
            if (s3[i-1] == s1[i-1]) {
                dp[i][0] = true;
            } else {
                break;
            }
        }
        for (auto i = 0; i <= n; ++i) {
            if (s3[i-1] == s2[i-1]) {
                dp[0][i] = true;
            } else {
                break;
            }
        }
        for (auto i = 1; i <= m; ++i) {
            for (auto j = 1; j <= n; ++j) {
                dp[i][j] = (s3[i+j-1] == s1[i-1] && dp[i-1][j]) ||
                           (s3[i+j-1] == s2[j-1] && dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
