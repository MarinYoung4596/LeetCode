/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.


Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> solution; // each solution
        vector<int> columns(n, 0);

        dfs(res, columns, 0, n);

        return res;
    }

private:
    void dfs(vector<vector<string>> &res,
             vector<int> &columns,
             const int curr, const int &N){
        if (curr == N) { // to the end of the row; each solution
             vector<string> solution;
             for (auto i = 0; i < N; ++i) {
                 string row(N, '.');    // "....", each row
                 row[columns[i]] = 'Q'; // QUEENS[i][columns[i] ] = 'Q'
                 solution.push_back(row);
             }
             res.push_back(solution);
             return;
        }

        for (auto j = 0; j < N; ++j) { // column
            columns[curr] = j; // put queen at [curr][j]
            bool _is_valid = isValid(columns, curr, j); // not conflict with previous queen
            if (_is_valid) {
                dfs(res, columns, curr + 1, N); // to the next row
            }
        }
    }

    bool isValid(const vector<int> &columns, const int &row, const int &column) { // 第row行第column列是否跟已经摆放的位置冲突
        for (auto i = 0; i < row; ++i) { // get the column of the queen in each row
            if (columns[i] == column || /* same column */
                    abs(row - i) == abs(columns[i] - column) /* catercorner */) {
                return false;
            }
        }
        return true;
    }
};
