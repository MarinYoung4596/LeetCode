/*

72. Edit Distance

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:
    a) Insert a character
    b) Delete a character
    c) Replace a character
*/

class Solution {
public:
    int minDistance(string &word1, string &word2) {
        if (word1.empty()) {
            return word2.size();
        }
        if (word2.empty()) {
            return word1.size();
        }

        const auto row = word1.size() + 1;
        const auto col = word2.size() + 1;
        vector<vector<int>> dp(row, vector<int>(col, 0));

        for (auto i = 1; i < row; ++i) {
            dp[i][0] = i;
        }
        for (auto j = 1; j < col; ++j) {
            dp[0][j] = j;
        }

        for (auto i = 1; i < row; ++i) {
            for (auto j = 1; j < col; ++j) {
                dp[i][j] = (word1[i - 1] == word2[j - 1]) ? \
                                dp[i - 1][j - 1] : \
                                (dp[i - 1][j - 1] + 1);
                int tmp = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                dp[i][j] = min(dp[i][j], tmp);
            }
        }
        return dp[row - 1][col - 1];
    }
};
