/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1254.NumberOfClosedIslands.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/12 23:07:32
*   @brief:

Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.


Example 1:
    Input: grid = [[1,1,1,1,1,1,1,0],
                    [1,0,0,0,0,1,1,0],
                    [1,0,1,0,1,1,1,0],
                    [1,0,0,0,0,1,0,1],
                    [1,1,1,1,1,1,1,0]]
    Output: 2
    Explanation: Islands in gray are closed because they are completely surrounded by water (group of 1s).

Example 2:
    Input: grid = [[0,0,1,0,0],
                    [0,1,0,1,0],
                    [0,1,1,1,0]]
    Output: 1

Example 3:
    Input: grid = [[1,1,1,1,1,1,1],
                [1,0,0,0,0,0,1],
                [1,0,1,1,1,0,1],
                [1,0,1,0,1,0,1],
                [1,0,1,1,1,0,1],
                [1,0,0,0,0,0,1],
                [1,1,1,1,1,1,1]]
    Output: 2


Constraints:
    1 <= grid.length, grid[0].length <= 100
    0 <= grid[i][j] <=1

*****************************************************************/


class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        auto nrow = grid.size();
        auto ncolumn = grid[0].size();

        if (!nrow || !ncolumn) {
            return 0;
        }
        // 跳过边界
        for (auto j = 0; j < ncolumn; ++j) {
            dfs(grid, 0, j);  // 上边界
            dfs(grid, nrow - 1, j);  // 下边界
        }
        for (auto i = 0; i < nrow; ++i) {
            dfs(grid, i, 0);  // 左边界
            dfs(grid, i, ncolumn - 1); // 右边界
        }
        // 正式统计
        auto result = 0;
        for (auto i = 0; i < nrow; ++i) {
            for (auto j = 0; j < ncolumn; ++j) {
                if (grid[i][j] == 1) {  // 从0开始往边扩散
                    continue;
                }
                dfs(grid, i, j);
                ++result;
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<int>> &grid, int r, int c) {
        auto nrow = grid.size();
        auto ncolumn = grid[0].size();

        if (r < 0 || r >= nrow || c < 0 || c >= ncolumn) {
            return;
        }
        if (grid[r][c] == 1) {
            return;
        }
        grid[r][c] = 1;  // 遍历过的都置为1
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
    }
};