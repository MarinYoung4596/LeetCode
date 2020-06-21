/*
Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.


Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 10^5.
All elements in the matrix are distinct.
*/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        const auto m = matrix.size();
        const auto n = matrix[0].size();
        
        int row_min[m];
        int column_max[n];
        for (auto i = 0; i < m; ++i) { // row
            for (auto j = 0; j < n; ++j) { // column
                if (j == 0) { // 每行第一个元素
					row_min[i] = matrix[i][j];
				}
				row_min[i] = std::min(row_min[i], matrix[i][j]);
                if (i == 0) { // 每列第一个元素初始化
					column_max[j] = matrix[i][j];
				}
				column_max[j] = std::max(column_max[j], matrix[i][j]);
            }
        }
        
        std::vector<int> result;
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (matrix[i][j] == row_min[i] && matrix[i][j] == column_max[j]) {
                    result.push_back(matrix[i][j]);
                }
            }
        }
        
        return result;
    }
};