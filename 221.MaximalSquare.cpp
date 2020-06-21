/*

221. Maximal Square 

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.

*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // dp[i][j]: the maximal ##size## of the square that can be achieved from point (0,0) to point (i, j)
        // dp[i][j] = matrix[i][j] if i == 0 || j == 0 // ±ß½çÌõ¼þ
        // dp[i][j] = 0            if i > 0 && j >0 && matrix[i][j] == 0
        // dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) if i > 0 && j > 0 && matrix[i][j] == 1
        const auto m = matrix.size();
        if (!m) return 0;
        const auto n = matrix[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        int maxsize = 0;
        for (int i = 0; i < m; ++i)
        {
            dp[i][0] = matrix[i][0] - '0';
            maxsize = max(maxsize, dp[i][0]);
        }
        for (int j = 0; j < n; ++j)
        {
            dp[0][j] = matrix[0][j] - '0';
            maxsize = max(maxsize, dp[0][j]);
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (static_cast<int>(matrix[i][j] - '0') == 1)
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                maxsize = max(maxsize, dp[i][j]);
            }
        }
        return maxsize * maxsize;
    }
};