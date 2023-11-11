/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    329.LongestIncreasingPathInAMatrix.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/11 15:36:19
*   @brief:

Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).


Example 1:
    (pic)
    Input: matrix = [
        [9,9,4],
        [6,6,8],
        [2,1,1]
    ]
    Output: 4
    Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:
    (pic)
    Input: matrix = [
        [3,4,5],
        [3,2,6],
        [2,2,1]
    ]
    Output: 4
    Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Example 3:
    Input: matrix = [[1]]
    Output: 1


Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 200
    0 <= matrix[i][j] <= 2^31 - 1

*****************************************************************/


class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const auto m = matrix.size();
        const auto n = matrix[0].size();
        vector<vector<int>> paths(m, vector<int>(n, 1));
        int result = 1;
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                auto cur_path = dfs(matrix, paths, i, j);
                result = max(cur_path, result);
            }
        }
        return result;
    }

private:
    int dfs(const vector<vector<int>> &matrix,
            vector<vector<int>> &paths,
            int row, int column) {
        if (paths[row][column] != 1) {
            return paths[row][column];
        }
        vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto item : moves) {
            auto new_row = row + item.first;
            auto new_column = column + item.second;
            if (new_row < 0 || new_row >= matrix.size() ||
                    new_column < 0 || new_column >= matrix[0].size()) { // 不合法
                continue;
            }
            if (matrix[row][column] >= matrix[new_row][new_column]) { // 非递增
                continue;
            }
            auto cur_path = dfs(matrix, paths, new_row, new_column);
            paths[row][column] = max(paths[row][column], cur_path + 1);
        }
        return paths[row][column];
    }
};