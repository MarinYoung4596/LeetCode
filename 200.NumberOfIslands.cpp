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
        std::vector<std::vector<bool>> visited(grid.size(),
                                              std::vector<bool>(grid[0].size(), false));
        int result = 0;
        for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < grid[0].size(); ++j) {
                if (visited[i][j]) {
                    continue;
                }
                if (grid[i][j] == '0') {
                    continue;
                }
                dfs(grid, visited, i, j);
                ++result;
            }
        }
        return result;
    }

private:
    void dfs(const std::vector<std::vector<char>> &grid,
            std::vector<std::vector<bool>> &visited,
            int i, int j) {
        if (i < 0
                || i >= grid.size()
                || j < 0
                || j > grid[0].size()
                || visited[i][j]
                || grid[i][j] == '0') {
            return;
        }
        visited[i][j] = true;
        dfs(grid, visited, i + 1, j);
        dfs(grid, visited, i - 1, j);
        dfs(grid, visited, i, j + 1);
        dfs(grid, visited, i, j - 1);
    }
};