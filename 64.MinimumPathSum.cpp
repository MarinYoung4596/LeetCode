/*

64. Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

*/


// First Solution: Space Complexity: O(MN)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        const auto m = grid.size();
        const auto n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];
        for (auto i = 1; i < m; ++i) {
            dp[i][0] = (dp[i - 1][0] + grid[i][0]);
        }
        for (auto j = 1; j < n; ++j) {
            dp[0][j] = (dp[0][j - 1] + grid[0][j]);
        }
        for (auto i = 1; i < m; ++i) {
            for (auto j = 1; j < n; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] += grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};


// Second Solution: Space Complexity: O(1)
class Solution2 {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < grid[0].size(); ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                auto up = (i == 0 ? INT_MAX : grid[i - 1][j]);
                auto left = (j == 0 ? INT_MAX : grid[i][j - 1]);
                grid[i][j] += std::min(up, left);
            }
        }
        return grid.back().back();
    }
};
