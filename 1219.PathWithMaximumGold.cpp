/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1219.PathWithMaximumGold.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/12 23:47:27
*   @brief:

In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.
Return the maximum amount of gold you can collect under the conditions:
* Every time you are located in a cell you will collect all the gold in that cell.
* From your position, you can walk one step to the left, right, up, or down.
* You can't visit the same cell more than once.
* Never visit a cell with 0 gold.
* You can start and stop collecting gold from any position in the grid that has some gold.


Example 1:
    Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
    Output: 24
    Explanation:
        [[0,6,0],
        [5,8,7],
        [0,9,0]]
        Path to get the maximum gold, 9 -> 8 -> 7.

Example 2:
    Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
    Output: 28
    Explanation:
        [[1,0,7],
        [2,0,6],
        [3,4,5],
        [0,3,0],
        [9,0,20]]
        Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 15
    0 <= grid[i][j] <= 100
    There are at most 25 cells containing gold.
*****************************************************************/


class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        auto nrow = grid.size();
        auto ncolumn = grid[0].size();

        vector<vector<bool>> visited(nrow, vector<bool>(ncolumn, false));
        auto result = 0;
        for (auto i = 0; i < nrow; ++i) {
            for (auto j = 0; j < ncolumn; ++j) {
                if (!grid[i][j] || visited[i][j]) {
                    continue;
                }
                auto tmp = backtrack(grid, visited, i, j);
                result = std::max(tmp, result);
            }
        }
        return result;
    }

private:
    int backtrack(vector<vector<int>> &grid,
                    vector<vector<bool>> &visited,
                    int r, int c) {
        auto nrow = grid.size();
        auto ncolumn = grid[0].size();
        if (r < 0 || c < 0 || r >= nrow || c >= ncolumn) {
            return 0;
        }
        if (!grid[r][c]) {
            return 0;
        }
        if (visited[r][c]) {
            return 0;
        }
        visited[r][c] = true;
        auto up = backtrack(grid, visited, r - 1, c);
        auto down = backtrack(grid, visited, r + 1, c);
        auto left = backtrack(grid, visited, r, c - 1);
        auto right = backtrack(grid, visited, r, c + 1);
        visited[r][c] = false;
        auto max_value = std::max(up,
                                std::max(down,
                                         std::max(left, right)));
        return grid[r][c] + max_value;
    }
};