/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
    Input:
        11110
        11010
        11000
        00000
    Output: 1


Example 2:
    Input:
        11000
        11000
        00100
        00011
    Output: 3

*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        vector<vector<bool>> visited(grid.size(),
                                     vector<bool>(grid[0].size(), false));
        int result = 0;
        for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < grid[0].size(); ++j) {
                if (visited[i][j]) {
                    continue;
                }
                if (grid[i][j] == '0') {  // 当前节点非陆地, 无需遍历
                    continue;
                }
                dfs(grid, visited, i, j); // 类似扫雷,当前节点是陆地,把相邻的陆地都标记为 visited, 防止重复遍历
                ++result;
            }
        }
        return result;
    }

private:
    void dfs(const vector<vector<char>> &grid,
             vector<vector<bool>> &visited,
             int i, int j) {
        auto nrow = grid.size();
        auto ncolumn = grid[0].size();
        if (i < 0 || i >= nrow || j < 0 || j > ncolumn) { // 数组越界
            return;
        }
        if (visited[i][j]) { // 访问过
            return;
        }
        if (grid[i][j] == '0') { // 到达边界,无需继续遍历
            return;
        }
        visited[i][j] = true;
        dfs(grid, visited, i - 1, j); // 上
        dfs(grid, visited, i + 1, j); // 下
        dfs(grid, visited, i, j - 1); // 左
        dfs(grid, visited, i, j + 1); // 右
    }
};
