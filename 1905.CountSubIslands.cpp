/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1905.CountSubIslands.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/12 23:31:41
*   @brief:

You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.
An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.
Return the number of islands in grid2 that are considered sub-islands.

Example 1:
    Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
    Output: 3
    Explanation:
        In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
        The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.

Example 2:
    Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
    Output: 2
    Explanation:
        In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
        The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.

Constraints:
    m == grid1.length == grid2.length
    n == grid1[i].length == grid2[i].length
    1 <= m, n <= 500
    grid1[i][j] and grid2[i][j] are either 0 or 1.
*****************************************************************/


class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        auto nrow = grid1.size();
        auto ncolumn = grid1[0].size();

        // 如果岛屿 B 中存在⼀⽚陆地，在岛屿 A 的对应位置是海⽔，那么岛屿 B 就不是岛屿 A 的⼦岛
        // 因此第一遍遍历，把这样的岛屿找出来，剔除掉
        for (auto i = 0; i < nrow; ++i) {
            for (auto j = 0; j < ncolumn; ++j) {
                if (grid1[i][j] == 0 && grid2[i][j] == 1) {
                    dfs(grid2, i, j);
                }
            }
        }
        // 第二遍遍历，寻找子岛屿的数量
        auto result = 0;
        for (auto i = 0; i < nrow; ++i) {
            for (auto j = 0; j < ncolumn; ++j) {
                if (!grid2[i][j]) {
                    continue;
                }
                dfs(grid2, i, j);
                ++result;
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<int>> &grid, int r, int c) {
        auto nrow = grid.size();
        auto ncolumn = grid[0].size();
        if (r < 0 || c < 0 || r >= nrow || c >= ncolumn) {
            return;
        }
        if (!grid[r][c]) {
            return;
        }
        grid[r][c] = 0;
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }
};
