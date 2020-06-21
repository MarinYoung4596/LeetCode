/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.


Constraints:
    board and word consists only of lowercase and uppercase English letters.
    1 <= board.length <= 200
    1 <= board[i].length <= 200
    1 <= word.length <= 10^3
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty()) {
            return false;
        }
        std::vector<std::vector<bool>> stats(board.size(),
                                             std::vector<bool>(board[0].size(), false));
        for (auto i = 0; i < board.size(); ++i) {
            for (auto j = 0; j < board[0].size(); ++j) {
                auto stat = backtrack(board, word, 0, i, j, stats); // 从i,j 开始搜索
                if (stat) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool backtrack(
            const std::vector<std::vector<char>> &board,
            const std::string &word,
            int step,
            int row,
            int column,
            std::vector<std::vector<bool>> &stat) {
        if (step == word.size()) { // 到底
            return true;
        }
        if (row < 0 || row >= board.size()
                || column < 0 || column >= board[0].size()) { // 非法参数
            return false;
        }
        if (stat[row][column]) { // 已经遍历过
            return false;
        }
        if (word[step] != board[row][column]) { // 不相等
            return false;
        }
        stat[row][column] = true;
        auto stat1 = backtrack(board, word, step + 1, row, column - 1, stat); // 向左
        auto stat2 = backtrack(board, word, step + 1, row, column + 1, stat); // 向右
        auto stat3 = backtrack(board, word, step + 1, row - 1, column, stat); // 向上
        auto stat4 = backtrack(board, word, step + 1, row + 1, column, stat); // 向下
        stat[row][column] = false;

        return (stat1 || stat2 || stat3 || stat4);
    }
};