/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    576.OutOfBoundaryPaths.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/12/03 23:05:27
*   @brief:
*
*****************************************************************/


/**
 * @brief First Solution: dfs
 * 时间复杂度：O(4^{move})
 * Time Limit Exceeded
 */
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        return dfs(m, n, maxMove, startRow, startColumn, 0);
    }

private:
    int dfs(int m, int n, int move,
            int x, int y, int path_num) {
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return path_num + 1;
        }
        if (move == 0) {
            return 0;
        }
        auto up = dfs(m, n, move - 1, x - 1, y, path_num);
        auto down = dfs(m, n, move - 1, x + 1, y, path_num);
        auto left = dfs(m, n, move - 1, x, y - 1, path_num);
        auto right = dfs(m, n, move - 1, x, y + 1, path_num);
        uint64_t res = up + down + left + right;
        return static_cast<int>((res) % static_cast<int>(1e9 + 7));
    }
};

/**
 * @brief Second Solution: 记忆化搜索
 * 注意，其实也是 dfs 改进，只不过用三维数组记录 move 次数
 */
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // 用 m * n * move 的矩阵，记录不同步数下的总路径数
        vector<vector<vector<int>>> visited(m,
                                            vector<vector<int>>(n,
                                                                vector<int>(maxMove + 1, -1)));
        return dfs(m, n, maxMove, startRow, startColumn, visited);
    }

private:
    int dfs(int m, int n, int move,
            int x, int y,
            vector<vector<vector<int>>> &visited) {
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return 1;
        }
        if (visited[x][y][move] != -1) {
            return visited[x][y][move];
        }
        if (move <= 0) {
            return 0;
        }
        uint64_t res = 0;
        res += dfs(m, n, move - 1, x - 1, y, visited);  // up
        res += dfs(m, n, move - 1, x + 1, y, visited); // down
        res += dfs(m, n, move - 1, x, y - 1, visited); // left
        res += dfs(m, n, move - 1, x, y + 1, visited); // right
        visited[x][y][move] = static_cast<int>((res) % static_cast<int>(1e9 + 7));
        return visited[x][y][move];
    }
};