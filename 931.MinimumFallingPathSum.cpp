/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    931.MinimumFallingPathSum.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/02/20 21:29:51
*   @brief:

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).


Example 1:
    Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
    Output: 13
    Explanation: There are two falling paths with a minimum sum as shown.

Example 2:
    Input: matrix = [[-19,57],[-40,-5]]
    Output: -59
    Explanation: The falling path with a minimum sum is shown.


Constraints:
    n == matrix.length == matrix[i].length
    1 <= n <= 100
    -100 <= matrix[i][j] <= 100

*****************************************************************/

// dp
class Solution {
public:
    // dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i - 1][j + 1])

    int minFallingPathSum(vector<vector<int>> &matrix) {
        const auto n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        // 自底向上
        auto result = INT_MAX;
        for (auto j = 0; j < n; ++j) {
            auto subres = dfs(matrix, n - 1, j, dp);
            result = std::min(result, subres);
        }
        return result;
    }

private:
    int dfs(const vector<vector<int>> &matrix, int i, int j,
            vector<vector<int>> &cache) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) {
            return INT_MAX;
        }
        if (i == 0) {  // 到了第一行
            return matrix[0][j];
        }
        if (cache[i][j] != INT_MAX) {
            return cache[i][j];
        }
        // 从上一行 左、中、右 位置下降
        cache[i][j] = matrix[i][j] + \
                      triplet_min(dfs(matrix, i - 1, j, cache),
                                  dfs(matrix, i - 1, j - 1, cache),
                                  dfs(matrix, i - 1, j + 1, cache));
        return cache[i][j];
    }

    int triplet_min(int a, int b, int c) {
        return std::min(a, std::min(b, c));
    }
};
