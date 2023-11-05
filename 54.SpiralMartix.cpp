/*

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
    Given the following matrix:
    [
        [ 1, 2, 3 ],
        [ 4, 5, 6 ],
        [ 7, 8, 9 ]
    ]
You should return [1,2,3,6,9,8,7,4,5].

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        const auto m = matrix.size();
        if (0 == m) {
            return res;
        }
        const auto n = matrix[0].size();

        for (auto start = 0; (2 * start) < m && (2 * start) < n; ++start) {
            auto row_end = m - 1 - start;
            auto column_end = n - 1 - start;

            if (start == row_end) {
                for (auto i = start; i <= column_end; ++i) {
                    res.push_back(matrix[start][i]);
                }
                return res;
            }
            if (start == column_end) {
                for (auto i = start; i <= row_end; ++i) {
                    res.push_back(matrix[i][start]);
                }
                return res;
            }

            for (int i = start; i < column_end; ++i) {
                res.push_back(matrix[start][i]);
            }
            for (int i = start; i < row_end; ++i) {
                res.push_back(matrix[i][column_end]);
            }
            for (int i = column_end; i > start; --i) {
                res.push_back(matrix[row_end][i]);
            }
            for (int i = row_end; i > start; --i) {
                res.push_back(matrix[i][start]);
            }
        }
        return res;
    }
};


// Second Solution :
/**
input:
[[1,2,3],[4,5,6],[7,8,9]]
[[1,2,3,4],[5,6,7,8],[9,10,11,12]]
[[1,2,3]]
[[1],[2],[3]]

output:
[1,2,3,6,9,8,7,4]
[1,2,3,4,8,12,11,10,9,5,6,7]
[1,2,3,2]
[1,2,3,2]

expected:
[1,2,3,6,9,8,7,4,5]
[1,2,3,4,8,12,11,10,9,5,6,7]
[1,2,3]
[1,2,3]
 */
class Solution2 {
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        if (matrix.empty()) {
            return std::vector<int>();
        }
        int left = 0;
        int right = matrix[0].size() - 1;
        int up = 0;
        int down = matrix.size() - 1;

        std::vector<int> result;
        while ((left >= 0 && left <= right)
                && (up >= 0 && up <= down)) {
            for (auto i = left; i <= right; ++i) {
                result.push_back(matrix[up][i]);
            }
            if (up < down) {
                for (auto i = up + 1; i <= down; ++i) {
                    result.push_back(matrix[i][right]);
                }
            }
            if (up < down && left < right) {
                for (auto i = right - 1; i >= left; --i) {
                    result.push_back(matrix[down][i]);
                }
            }
            if (up < down && left < right) {
                for (auto i = down - 1; i > up; --i) {
                    result.push_back(matrix[i][left]);
                }
            }

            ++left;
            --right;
            ++up;
            --down;
        }
        return result;
    }
};
