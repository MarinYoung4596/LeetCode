/*
https://leetcode.com/problems/sudoku-solver/

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:
    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
    Empty cells are indicated by the character '.'.


    (pic)
    A sudoku puzzle...
    (pic)

    ...and its solution numbers marked in red.

Note:
    The given board contain only digits 1-9 and the character '.'.
    You may assume that the given Sudoku puzzle will have a single unique solution.
    The given board size is always 9x9.
*/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }

private:
    bool backtrack(std::vector<std::vector<char>> &board,
                  int i, int j) {
        if (j == 9) { // 到列尾，跳到下一行
            return backtrack(board, i + 1, 0);
        }
        if (i == 9) { // 遍历完成
            return true;
        }
        if (board[i][j] != '.') {// 该位置已经有值，跳过，填下一个
            return backtrack(board, i, j + 1);
        }
        for (char ch = '1'; ch <= '9'; ++ch) {
            if (!is_valid(board, i, j, ch)) {
                continue;
            }
            board[i][j] = ch; // 选择填入ch
            auto stat = backtrack(board, i, j + 1);
            if (stat) {
                return true;
            }
            board[i][j] = '.'; // 不选择填入ch, 填下一个数字
        }
        return false;
    }

    // 判断board[row][column] 填入value 是否合法
    bool is_valid(std::vector<std::vector<char>> &board,
                 int row, int column, char value) {
        for (auto k = 0; k < 9; ++k) {
            if (board[row][k] == value) { // 行
                return false;
            }
            if (board[k][column] == value) { // 列
                return false;
            }
        }
        // // 3*3 sub-box
        auto get_start_index = [](int n) { return 3 * (n / 3); };
        auto row_start = get_start_index(row);
        auto column_start = get_start_index(column);
        for (auto i = row_start; i < row_start + 3; ++i) {
            for (auto j = column_start; j < column_start + 3; ++j) {
                if (board[i][j] == value) {
                    return false;
                }
            }
        }
        return true;
    }
};