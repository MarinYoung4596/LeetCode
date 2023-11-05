/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    85.MaximalRectangle.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/28 21:39:13
*   @brief:

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.


Example 1:
    (pic)
    Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    Output: 6
    Explanation: The maximal rectangle is shown in the above picture.

Example 2:
    Input: matrix = [["0"]]
    Output: 0

Example 3:
    Input: matrix = [["1"]]
    Output: 1


Constraints:
    rows == matrix.length
    cols == matrix[i].length
    1 <= row, cols <= 200
    matrix[i][j] is '0' or '1'.

*****************************************************************/

// First Solution：暴力解法;
// 时间复杂度：O(M * M * N)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const auto nrow = matrix.size();
        const auto ncolumn = matrix[0].size();
        vector<vector<int>> m(nrow, vector<int>(ncolumn, 0));  // 记录每行【以当前列结尾】的【连续1个数】
        auto max_area = 0;
        for (auto i = 0; i < nrow; ++i) {
            for (auto j = 0; j < ncolumn; ++j) {
                if (matrix[i][j] == '0') {
                    m[i][j] = 0;
                } else {
                    m[i][j] = j == 0 ? 1 : m[i][j - 1] + 1;
                }
                // e.g.  matrix[i] = [1, 1, 0, 1, 1, 1, 1, 0, 1] ==> m[i] = [1, 2, 0, 1, 2, 3, 4, 0, 1]
                auto min_width = m[i][j];
                for (auto r = i; r >= 0; --r) {
                    auto height = i - r + 1;
                    min_width = std::min(min_width, m[r][j]);  // 最小宽度决定了最大面积
                    max_area = std::max(max_area, height * min_width);
                }
            }
        }
        return max_area;
    }
};

// Second Solution: 单调栈
class Solution {
public:
    // 类似84题。只不过84题算好了高。这里需要自己抽象
    int maximalRectangle(vector<vector<char>>& matrix) {
        const auto nrow = matrix.size();
        const auto ncolumn = matrix[0].size();
        vector<vector<int>> prefix_sum(nrow, vector<int>(ncolumn, 0)); // p[i][j] : 第i 行，以 j 结尾的连续1个数
        for (auto i = 0; i < nrow; ++i) {
            for (auto j = 0; j < ncolumn; ++j) {
                if (matrix[i][j] == '0') {
                    continue;
                }
                prefix_sum[i][j] = (j == 0 ? 1 : prefix_sum[i][j - 1] + 1);
            }
        }
        int max_area = 0;
        // 看做以 y 轴为底，向 x 轴横向生长的柱状图
        for (auto j = 0; j < ncolumn; ++j) {
            vector<int> up(nrow, 0);   // 向上找最小值,up[i] 代表 prefix_sum[i][j] 往上数，第一个比它小的元素下标
            stack<int> sup;
            for (auto i = 0; i < nrow; ++i) {
                while (!sup.empty() && prefix_sum[i][j] <= prefix_sum[sup.top()][j]) {
                    sup.pop();
                }
                up[i] = sup.empty() ? 0 : sup.top() + 1;
                sup.push(i);
            }
            vector<int> down(nrow, 0);  // 向下找最小值
            stack<int> sdown;
            for (int i = nrow - 1; i >= 0; --i) {
                while (!sdown.empty() && prefix_sum[i][j] < prefix_sum[sdown.top()][j]) {
                    sdown.pop();
                }
                down[i] = sdown.empty() ? nrow - 1 : sdown.top() - 1;
                sdown.push(i);
            }
            for (auto i = 0; i < nrow; ++i) {
                auto cur_area = prefix_sum[i][j] * (down[i] - up[i] + 1);
                max_area = std::max(max_area, cur_area);
            }
        }
        return max_area;
    }
};