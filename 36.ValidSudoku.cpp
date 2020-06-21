/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:
Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true


Example 2:
Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.


Note:
    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.
    The given board contain only digits 1-9 and the character '.'.
    The given board size is always 9x9.
*/

class Solution {
public:
       bool isValidSudoku(vector<vector<char>>& board) {
        for (auto i = 0; i < 9; ++i) {
            std::vector<bool> row_num(10, false);
            std::vector<bool> column_num(10, false);
            for (auto j = 0; j < 9; ++j) {
                // 行
                if (board[i][j] != '.') {
                    int cur_num = static_cast<int>(board[i][j] - '0');
                    if (row_num[cur_num]) {
                        return false;
                    }
                    row_num[cur_num] = true;
                }
                // 列
                if (board[j][i] != '.') {
                    int cur_num = static_cast<int>(board[j][i] - '0');
                    if (column_num[cur_num]) {
                        return false;
                    }
                    column_num[cur_num] = true;
                }
            }
        }

        // 检查小方格
        for (auto i = 0; i < 3; ++i) {
            for (auto j = 0; j < 3; ++j) {
                auto res = check_valid(board, i * 3, j * 3);
                if (!res) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool check_valid(const std::vector<std::vector<char>> &board,
                    int row, int column) {
        std::vector<bool> grid_num(10, false);
        for (auto i = row; i < row + 3; ++i) {
            for (auto j = column; j < column + 3; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                auto num = static_cast<int>(board[i][j] - '0');
                if (grid_num[num]) {
                    return false;
                }
                grid_num[num] = true;
            }
        }
        return true;
    }
};