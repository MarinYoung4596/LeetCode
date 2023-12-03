/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    498.DiagonalTraverse.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/12/03 17:56:13
*   @brief:

Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.


Example 1:
    (pic)(非常重要)
    Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [1,2,4,7,5,3,6,8,9]

Example 2:
    Input: mat = [[1,2],[3,4]]
    Output: [1,2,3,4]


Constraints:
    m == mat.length
    n == mat[i].length
    1 <= m, n <= 10^4
    1 <= m * n <= 10^4
    -10^5 <= mat[i][j] <= 10^5

*****************************************************************/

#include "util.h"
#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

/**
 * @brief 索引迭代法
 */
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;

        const auto m = mat.size();
        const auto n = mat[0].size();
        auto i = 0;
        auto j = 0;
        auto direction = 1;  // 1 means left-to-right; -1 means right-to-left
        while (result.size() != m * n) {
            if (i >= 0 && i < m && j >= 0 && j < n) {
                result.push_back(mat[i][j]);
            }
            // 先更新索引
            auto tmp_i = direction == 1 ? i - 1 : i + 1;
            auto tmp_j = direction == 1 ? j + 1 : j - 1;
            // 如果不合法，立即更新索引值
            if (tmp_i < 0 || tmp_i >= m || tmp_j < 0 || tmp_j >= n) {
                if (direction == 1) {
                    tmp_i = (j == n - 1) ? i + 1 : i;
                    tmp_j = (j == n - 1) ? j : j + 1;
                } else {
                    tmp_i = (i == m - 1) ? i : i + 1;
                    tmp_j = (i == m - 1) ? j + 1 : j;
                }
                direction *= -1;  // 同时改变遍历方向
            }
            i = tmp_i;
            j = tmp_j;
        }
        return result;
    }
};

/**
 * @brief 对角线法
 */
class Solution2 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;

        const auto m = mat.size();
        const auto n = mat[0].size();
        for (int i = 0; i < m + n - 1; ++i) {  // 总对角线条数：m + n - 1
            if (i % 2) { // 奇数编号
                int x = i < n ? 0 : i - (n - 1);
                int y = i < n ? i : n - 1;
                while (x < m && y >= 0) {
                    result.push_back(mat[x][y]);
                    ++x;
                    --y;
                }
            } else {
                int x = i < m ? i : m - 1;
                int y = i < m ? 0 : i - (m - 1);
                while (x >= 0 && y < n) {
                    result.push_back(mat[x][y]);
                    --x;
                    ++y;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    print_matrix(matrix);
    Solution s;
    auto res = s.findDiagonalOrder(matrix);
    print_vector(res);

    return 0;
}