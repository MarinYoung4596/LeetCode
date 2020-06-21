/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:
Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]


Example 2:
Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]


Follow up:
    A straight forward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const auto m = matrix.size();
        const auto n = matrix[0].size();

        bool first_row_has_zero = false;
        for (auto j = 0; j < n; ++j) {
            if (!matrix[0][j]) {
                first_row_has_zero = true;
                break;
            }
        }
        bool first_column_has_zero = false;
        for (auto i = 0; i < m; ++i) {
            if (!matrix[i][0]) {
                first_column_has_zero = true;
                break;
            }
        }

        for (auto i = 1; i < m; ++i) {
            for (auto j = 1; j < n; ++j) {
                if (!matrix[i][j]) {
                    matrix[i][0] = 0; // 第i行0列, 保存index
                    matrix[0][j] = 0; // 第0行j列, 保存index
                }
            }
        }
        for (auto i = 1; i < m; ++i) {
            for (auto j = 1; j < n; ++j) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0; // 除第一行第一列外，打标记的全部置0
                }
            }
        }
        if (first_row_has_zero) {
            for (auto j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (first_column_has_zero) {
            for (auto i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }

    }
};