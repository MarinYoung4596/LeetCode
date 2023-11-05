/*

Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
_________________
|3   0  1  4   2|
|5   6  3  2   1|
|  ___________  |
|1 | 2  0  1 | 5|
|4 | 1  0  1 | 7|
|1 | 0  3  0 | 5|
|  -----------  |
-----------------
Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
    Given matrix = [
        [3, 0, 1, 4, 2],
        [5, 6, 3, 2, 1],
        [1, 2, 0, 1, 5],
        [4, 1, 0, 1, 7],
        [1, 0, 3, 0, 5]
    ]

    sumRegion(2, 1, 4, 3) -> 8
    sumRegion(1, 1, 2, 2) -> 11
    sumRegion(1, 2, 2, 4) -> 12

Note:
    You may assume that the matrix does not change.
    There are many calls to sumRegion function.
    You may assume that row1 �� row2 and col1 �� col2.

// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
*/

#include <vector>
#include <iostream>

using std::vector;

// First Solution: Time Limit Exceeded
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) : dp(matrix) {}

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for (int i = row1; i <= row2; ++i) {
            for (int j = col1; j <= col2; ++j) {
                res += dp[i][j];
            }
        }
        return res;
    }

private:
    vector<vector<int>> dp;
};


// second Solution
class NumMatrix2 {
public:
    NumMatrix2(vector<vector<int>> &matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> tmp(matrix[i]);
            for (int j = 1; j < tmp.size(); ++j) {
                tmp[j] += tmp[j - 1];
            }
            dp.push_back(tmp);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for (int i = row1; i <= row2; ++i) {
            int x = (!col1 ? dp[i][col1] : dp[i][col1] - dp[i][col1 - 1]);
            res += (dp[i][col2] - dp[i][col1] + x);
        }
        return res;
    }

private:
    vector<vector<int>> dp;
};


// Third Solution, more faster
//   Sum(row1, col1, row2, col2)
// = Sum(0, 0, row2, col2) - Sum(0, 0, row1, col2) - Sum(0, 0, row2, col1) + Sum(0, 0, row1, col1)
class NumMatrix3 {
public:
    NumMatrix3(vector<vector<int> > &matrix) : dp(matrix) {
        for (int i = 0; i < matrix.size(); ++i) { // row
            for (int j = 0; j < matrix[i].size(); ++j) { // colom
                if (j == 0) {
                    if (i == 0) {
                        dp[0][0] = matrix[0][0];
                    } else {
                        dp[i][0] += dp[i - 1][0];
                    }
                } else if (i == 0) {
                    dp[0][j] += dp[0][j - 1];
                } else {
                    dp[i][j] += (dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1]);
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // Sum(row1, col1, row2, col2) = (dp[row2][col2] - dp[row1][col2] - dp[row2][col1] + dp[row1][col1])
        if (!row1) {
            if (!col1) {
                return dp[row2][col2];
            }
            return dp[row2][col2] - dp[row2][col1 - 1];
        } else if (!col1) {
            if (!row1) {
                return dp[row2][col2];
            }
            return dp[row2][col2] - dp[row1 - 1][col2];
        } else {
            return dp[row2][col2] - dp[row1 - 1][col2] - dp[row2][col1 - 1] + dp[row1 - 1][col1 - 1];
        }
    }

private:
    vector<vector<int> > dp;
};


int main() {
    int arr1[] = {3,0,1,4,2};
    int arr2[] = {5,6,3,2,1};
    int arr3[] = {1,2,0,1,5};
    int arr4[] = {4,1,0,1,7};
    int arr5[] = {1,0,3,0,5};

    vector<vector<int> > matrix;
    matrix.push_back(vector<int>(arr1, arr1 + sizeof(arr1) / sizeof(int)));
    matrix.push_back(vector<int>(arr2, arr2 + sizeof(arr2) / sizeof(int)));
    matrix.push_back(vector<int>(arr3, arr3 + sizeof(arr3) / sizeof(int)));
    matrix.push_back(vector<int>(arr4, arr4 + sizeof(arr4) / sizeof(int)));
    matrix.push_back(vector<int>(arr5, arr5 + sizeof(arr5) / sizeof(int)));

    NumMatrix numMatrix(matrix);
    std::cout << numMatrix.sumRegion(0, 1, 2, 3) << std::endl;
    std::cout << numMatrix.sumRegion(1, 2, 3, 4) << std::endl;
    std::cout << numMatrix.sumRegion(2, 1, 4, 3) << std::endl; // 8
    std::cout << numMatrix.sumRegion(1, 1, 2, 2) << std::endl; // 11
    std::cout << numMatrix.sumRegion(1, 2, 2, 4) << std::endl; // 12
    return 0;
}
