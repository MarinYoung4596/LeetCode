/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    542.01Matrix.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/13 23:01:01
*   @brief:

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.


Example 1:
    Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
    Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
    Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
    Output: [[0,0,0],[0,1,0],[1,2,1]]


Constraints:
    m == mat.length
    n == mat[i].length
    1 <= m, n <= 10^4
    1 <= m * n <= 10^4
    mat[i][j] is either 0 or 1.
    There is at least one 0 in mat.

*****************************************************************/

// First Solution : dfs: TLE
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        auto m = mat.size();
        auto n = mat[0].size();

        vector<vector<int>> distances(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (!mat[i][j]) {
                    continue;
                }
                auto min_dist = dfs(mat, visited, i, j);
                distances[i][j] = min_dist;
            }
        }
        return distances;
    }

private:
    int dfs(vector<vector<int>> &mat, vector<vector<bool>> &visited, int r, int c) {
        auto m = mat.size();
        auto n = mat[0].size();

        if (r < 0 || c < 0 || r >= m || c >= n) {
            return 100000;
        }
        if (visited[r][c]) {
            return 100000;
        }
        if (mat[r][c] == 0) {
            return 0;
        }
        visited[r][c] = true;
        auto left = dfs(mat, visited, r, c - 1);
        auto right = dfs(mat, visited, r, c + 1);
        auto up = dfs(mat, visited, r - 1, c);
        auto down = dfs(mat, visited, r + 1, c);
        auto min_dist = std::min(std::min(left, right),
                                 std::min(up, down));
        visited[r][c] = false;
        return min_dist + 1;
    }
};


// second solution: bfs
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        auto m = mat.size();
        auto n = mat[0].size();

        vector<vector<int>> distances(m, vector<int>(n, -1));
        queue<std::pair<int, int>> q;
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    continue;
                }
                q.push(std::make_pair(i, j));
                distances[i][j] = 0;
            }
        }
        // BFS，从值为0开始向四周扩散
        // 四周坐标(上，下，左，右)
        vector<pair<int, int>> paths = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (auto &p : paths) {
                auto next_r = cur.first + p.first;
                auto next_c = cur.second + p.second;
                if (next_r < 0 || next_c < 0 || next_r >= m || next_c >= n) {
                    continue;
                }
                if (distances[next_r][next_c] != -1) {
                    continue;
                }
                q.push(std::make_pair(next_r, next_c));
                // 当前距离等于上一个节点到0的距离+1
                distances[next_r][next_c] = 1 + distances[cur.first][cur.second];
            }
        }

        return distances;
    }

};