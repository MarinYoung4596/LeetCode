/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1289.MinimumFallingPathSumII.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/17 19:44:00
*   @brief:

Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.
A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.


Example 1:
    Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
    Output: 13
    Explanation: The possible falling paths are:
        [1,5,9], [1,5,7], [1,6,7], [1,6,8],
        [2,4,8], [2,4,9], [2,6,7], [2,6,8],
        [3,4,8], [3,4,9], [3,5,7], [3,5,9]
        The falling path with the smallest sum is [1,5,7], so the answer is 13.

Example 2:
    Input: grid = [[7]]
    Output: 7


Constraints:
    n == grid.length == grid[i].length
    1 <= n <= 200
    -99 <= grid[i][j] <= 99

*****************************************************************/

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& grid) {
        const auto n = grid.size();
        if (n == 1) {  // 特殊情况
            return grid[0][0];
        }

        // dp[i][j] 存储到满足条件的，到当前节点的最小路径
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        auto result = INT_MAX;
        for (auto j = 0; j < n; ++j) {
            auto tmp = dfs(grid, dp, n - 1, j);
            result = min(result, tmp);
        }
        return result;
    }

private:
    int dfs(vector<vector<int>> &grid,
            vector<vector<int>> &dp,
            int r, int c) {
        if (r < 0) {
            return 0;
        }
        if (dp[r][c] != INT_MAX) {
            return dp[r][c];
        }
        const auto n = grid.size();
        for (auto j = 0; j < n; ++j) {
            if (j == c) {
                continue;
            }
            auto tmp = grid[r][c] + dfs(grid, dp, r - 1, j);
            dp[r][c] = min(dp[r][c], tmp);
        }
        return dp[r][c];
    }
};