/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
    [[0,0,1,0,0,0,0,1,0,0,0,0,0],
    [0,0,0,0,0,0,0,1,1,1,0,0,0],
    [0,1,1,0,1,0,0,0,0,0,0,0,0],
    [0,1,0,0,1,1,0,0,1,0,1,0,0],
    [0,1,0,0,1,1,0,0,1,1,1,0,0],
    [0,0,0,0,0,0,0,0,0,0,1,0,0],
    [0,0,0,0,0,0,0,1,1,1,0,0,0],
    [0,0,0,0,0,0,0,1,1,0,0,0,0]]
    Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.

Example 2:
    [[0,0,0,0,0,0,0,0]]
    Given the above grid, return 0.


Note:
    The length of each dimension in the given grid does not exceed 50.
*/


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        vector<vector<bool>> visited(grid.size(),
                                     vector<bool>(grid[0].size(), false));
        int result = INT_MIN;
        for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < grid[0].size(); ++j) {
                auto area = dfs(grid, visited, i, j);
                result = std::max(result, area);
            }
        }
        return result;
    }

private:
    int dfs(const vector<vector<int>> &grid,
            vector<vector<bool>> &visited,
            int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return 0;
        }
        if (visited[i][j]) {
            return 0;
        }
        if (!grid[i][j]) {
            return 0;
        }
        visited[i][j] = true;
        auto up = dfs(grid, visited, i - 1, j);
        auto down = dfs(grid, visited, i + 1, j);
        auto left = dfs(grid, visited, i, j - 1);
        auto right = dfs(grid, visited, i, j + 1);
        return 1 + left + right + up + down;
    }
};
