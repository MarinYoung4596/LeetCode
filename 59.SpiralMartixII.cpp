/*
59. Spiral Matrix II

Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.

For example,
    Given n = 3, 
    You should return the following matrix: 
    [
        [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]
    ]

*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, std::vector<int>(n, 0));

        const auto end = (n % 2 == 1) ? (n / 2 + 1) : (n / 2);
        int start = 0, num = 0;
        while (start < end) {
            int row_end = n - 1 - start;
            int column_end = n - 1 - start;
            for (auto i = start; i <= column_end; ++i) {
                res[start][i] = ++num;
            }
            for (auto i = start + 1; i <= row_end; ++i) {
                res[i][column_end] = ++num;
            }
            for (auto i = column_end - 1; i >= start; --i) {
                res[row_end][i] = ++num;
            }
            for (auto i = row_end - 1; i >= (start + 1); --i) {
                res[i][start] = ++num;
            }
            ++start;
        }
        return res;
    }
};
