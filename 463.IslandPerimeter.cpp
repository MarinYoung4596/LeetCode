/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.


Example:
    Input:
        [[0,1,0,0],
        [1,1,1,0],
        [0,1,0,0],
        [1,1,0,0]]
    Output: 16
    Explanation: The perimeter is the 16 yellow stripes in the image below: (pic)

*/


// First Solution: dfs
// Runtime: 352 ms, faster than 5.87% of C++ online submissions for Island Perimeter.
// Memory Usage: 99.2 MB, less than 8.94% of C++ online submissions for Island Perimeter.
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        vector<vector<bool>> visited(grid.size(),
                                    vector<bool>(grid[0].size(), false));
        auto result = 0;
        for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < grid[0].size(); ++j) {
                if (!grid[i][j] || visited[i][j]) {
                    continue;
                }
                result = dfs(grid, visited, i, j);
                break;
            }
        }
        return result;
    }

private:
    int dfs(const vector<vector<int>> &grid,
            vector<vector<bool>> &visited,
            int i, int j) {
        if (i < 0
                || i >= grid.size()
                || j < 0
                || j >= grid[0].size()
                || !grid[i][j]) {
            return 1;
        }
        if (visited[i][j]) {
            return 0;
        }
        visited[i][j] = true;
        auto up = dfs(grid, visited, i - 1, j);
        auto down = dfs(grid, visited, i + 1, j);
        auto left = dfs(grid, visited, i, j - 1);
        auto right = dfs(grid, visited, i, j + 1);
        return up + down + left + right;
    }
};


// Second Solution: bruce force
// Runtime: 216 ms, faster than 21.52% of C++ online submissions for Island Perimeter.
// Memory Usage: 96.3 MB, less than 19.45% of C++ online submissions for Island Perimeter.
class Solution2 {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        auto result = 0;
        for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < grid[0].size(); ++j) {
                if (!grid[i][j]) {
                    continue;
                }
                if (i == 0 || !grid[i - 1][j]) { // up
                    ++result;
                }
                if (i + 1 == grid.size() || !grid[i + 1][j]) { // down
                    ++result;
                }
                if (j == 0 || !grid[i][j - 1]) { // left
                    ++result;
                }
                if (j + 1 == grid[0].size() || !grid[i][j + 1]) { // right
                    ++result;
                }
            }
        }
        return result;
    }
};
